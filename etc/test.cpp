#include <cmath>
#include <iostream>
using namespace std;
#define ll long long
const int M = 1e5 + 5;
int n, N;
int A[M];
int R;
ll error;
ll get(int l, int r) {  //求g[l] + g[l+1] + ... + g[r]
  if (l / R == r / R) return (ll)(l / R) * (r - l + 1);
  int a = l / R + 1, b = r / R - 1;
  ll res = (a - 1) * (ll)(a * R - l);          // left
  res += (b + 1) * (ll)(r - (b * R + R) + 1);  // right
  res += (ll)(b - a + 1) * (a + b) / 2 * R;    // mid,等差数列求和
  return res;
}
int main() {
  cin >> n >> N;
  for (int i = 1; i <= n; i++) cin >> A[i];
  A[n + 1] = N;
  R = N / (n + 1);
  for (int i = 0; i <= n; i++) {
    int l = A[i], r = A[i + 1] - 1;
    if (i >= r / R || i <= l / R) {
      error += abs((ll)(r - l + 1) * i - get(l, r));
    } else {
      int mid = i * R;
      error += abs((ll)(mid - l + 1) * i - get(l, mid));  // left
      error += abs((ll)(r - mid + 1) * i - get(mid, r));  // right
    }
  }
  cout << error;
  return 0;
}