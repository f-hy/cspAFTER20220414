#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e3;

int n;
vector<int> a(maxn + 1, 0);
ll sum = 0;
ll nnvar = 0;
// double sd = 0.0;//standard devitation

ll calSum() {
  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    res += a[i];
  }
  return res;
}
ll calnnVariance() {
  ll res = 0.0;
  for (int i = 1; i <= n; ++i) {
    res += a[i] * a[i];
  }
  res *= n;
  res -= sum * sum;
  return res;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sum = calSum();
  nnvar = calnnVariance();
  for (int i = 1; i <= n; ++i) {
    printf("%.16f\n", (a[i] * n - sum) / sqrt(nnvar));
  }
  return 0;
}