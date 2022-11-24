#include <bits/stdc++.h>
using namespace std;

const int maxn = 20 + 1;
const int maxc = 1e9 + 9;                 // cn<=1e9
int n, m;                                 // 0<=m<cn
int a[maxn], b[maxn], c[maxn], mc[maxn];  // ai>=2,0<=bi<ai
int prefixSumcb[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  c[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    c[i] = c[i - 1] * a[i];
    mc[i] = m % c[i];
  }
  for (int i = 1; i <= n; ++i) {
    b[i] = (mc[i] - prefixSumcb[i - 1]) / c[i - 1];
    prefixSumcb[i] = prefixSumcb[i - 1] + c[i - 2] * b[i - 1];
    cout << b[i] << ' ';
  }
  return 0;
}