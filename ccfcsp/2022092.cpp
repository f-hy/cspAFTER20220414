#include <bits/stdc++.h>
using namespace std;
const int maxn = 30 + 1;
const int maxa = 1e4;
int n, x, a[maxn], f[maxa * maxn][maxn];
// f[i][j]表示从第j本开始选，且必买第j本书时，总价超过i的最小值
int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  memset(f, 0b1, sizeof(f));
  for (int i = 1; i <= x; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[j] >= i) {  //仅仅选aj便已经符合条件
        f[i][j] = a[j];
        continue;
      }
      for (int k = j + 1; k <= n; ++k) {  //除了aj还要选其它
        f[i][j] = min(f[i][j], f[i - a[j]][k] + a[j]);
      }
    }
  }
  int ans = INT_MAX;
  for (int i = 1; i <= n; ++i) ans = min(ans, f[x][i]);
  cout << ans << endl;
  return 0;
}