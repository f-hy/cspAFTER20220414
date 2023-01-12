#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e2 + 2;
const int maxd2 = 1e2;
int d1[maxn], d2[maxn];  // d1存放每家店第一天价格，d2存放每家店第二天价格
int n;
bool flag;
bool vis[maxn][maxn][maxn];
// vis[i][j][k]用于记录当前是第i家店，前两家店第一天价格分别为j、k的情况是否被访问过
void dfs(int x, int s1, int s2) {
  //当前要枚举第x家店第一天的价格，并且第x-2家店的价格是s1，第x-1家店的价格是s2
  if (vis[x][s1][s2]) return;
  vis[x][s1][s2] = true;
  if (flag) return;  //进行最优化剪枝，flag=1表示已经搜索出答案
  if (x > n) {       //枚举完所有店的价格
    if ((d1[n] + d1[n - 1]) / 2 != d2[n]) return;
    //在枚举的时候，已经满足了1-n家店第一天的价格可以得到1~(n-1)家店第二天的价格
    //当前只需要判断n、n-1家店第一天的价格是否能得到第n家店第二天的价格就行
    flag = true;
    for (int i = 1; i <= n; ++i) {
      cout << d1[i] << ' ';
    }
    return;
  }
  if (x == 1) {  //对于第一家店，没有别的约束能知道其价格范围，只能从1到200枚举
    for (int i = 1; i <= 2 * maxd2; ++i) {
      d1[x] = i;
      dfs(x + 1, s2, d1[x]);
    }
  }
  if (x ==
      2) {  //对于第二家店，考虑从第一家店两天的价格推出其价格的范围，需要特殊处理
    for (int i = 0; i < 2; ++i) {
      d1[x] = d2[x - 1] * 2 - d1[x - 1] + i;
      if (d1[x] > 0) dfs(x + 1, s2, d1[x]);
    }
  }
  if (x >= 3) {
    //对于后面的店，都是考虑当前选择的价格，能否和前两家店第一天的价格（枚举得到）推出第二天前一家店的价格（题目给出）
    //通过第一天前两家店的价格和第二天前一家店的价格得到当前店价格的范围
    for (int i = 0; i < 3; ++i) {  //枚举除法时舍弃的余数
      d1[x] = d2[x - 1] * 3 - d1[x - 2] - d1[x - 1] + i;
      if (d1[x] > 0) dfs(x + 1, s2, d1[x]);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> d2[i];
  }
  dfs(1, 0, 0);
  return 0;
}