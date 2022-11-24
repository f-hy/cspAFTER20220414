// 国王游戏
// https://www.luogu.com.cn/problem/solution/P1080
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
const int maxn = 1e3 + 3;  // n
const int maxm = 1e4 + 4;  // a,b
int n;
int ans[maxm], prefix[maxm], tmp[maxm];
void div(int *dividends, int divisor, int *result, int len = maxm) {
  memset(result, 0, sizeof(result));
  int x = 0;
  for (int i = len - 1; i >= 0; --i) {
    x = x * 10 + dividends[i];
    result[i] = x / divisor;
    x %= divisor;
  }
}
bool cmp(int *a, int *b, int len = maxm) {
  for (int i = len - 1; i >= 0; --i) {
    if (a[i] > b[i]) return false;
    if (a[i] < b[i]) return true;
  }
  return true;
}
void mul_(int *a, int b, int len = maxm) {
  for (int i = maxm - 2; i >= 0; --i) a[i] *= b;
  for (int i = 0; i < maxm - 1; ++i) {
    a[i + 1] += (a[i] / 10);
    a[i] %= 10;
  }
  // a[0] *= b;
  // for (int i = 1; i < len - 1; ++i) {
  //   a[i] *= b;
  //   a[i] += (a[i - 1] / 10);
  //   a[i - 1] %= 10;
  // }
}
void print(int *a, int len = maxm) {
  bool flag = false;
  for (int i = len - 1; i >= 0; --i) {
    if (!flag) {
      if (a[i])
        flag = true;
      else
        continue;
    }
    cout << a[i];
  }
  cout << endl;
}
void copy(int *dest, int *src, int len = maxm) {
  for (int i = 0; i < len; ++i) dest[i] = src[i];
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  vector<pii> s(n + 1);  // king + secretary
  for (auto &i : s) {
    cin >> i.first >> i.second;
  }
  sort(s.begin() + 1, s.end(), [](pii &a, pii &b) {
    int o = max(a.first * a.second, b.second);
    int u = max(a.second, b.first * b.second);
    return o < u;  // not equal!
    // return a.first * a.second <= b.first * b.second;
  });
  prefix[0] = 1;  //乘积数组初始值为1 TODO
  for (int i = 0; i <= n; ++i) {
    div(prefix, s[i].second, tmp);
    if (cmp(ans, tmp)) copy(ans, tmp);  // memcpy(ans, tmp, maxm);???
    mul_(prefix, s[i].first);
  }
  print(ans);
  return 0;
}