#include <iostream>
using namespace std;
#define ll long long
const int maxn = 1e5 + 5;  //>10
const int maxs = 1e8;
int a[maxn];
ll sum, s;
int main() {
  int t;
  cin >> t;
  int n;
  while (t--) {
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    int ans = n + 1, l = 1;
    sum = 0;
    for (int i = 1; i <= n; ++i) {
      sum += a[i];
      while (sum >= s) {
        ans = min(ans, i - l + 1);
        sum -= a[l];
        ++l;
      }
    }
    if (ans == n + 1)
      cout << 0 << endl;
    else
      cout << ans << endl;
  }
  ios::sync_with_stdio(false);
  return 0;
}