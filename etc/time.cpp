#include <bits/stdc++.h>
using namespace std;
#define mem(f, v) memset(f, v, sizeof(f))
#define file(x)                  \
  freopen(#x ".in", "r", stdin); \
  freopen(#x ".out", "w", stdout);
#define pii pair<int, int>
typedef long long ll;
const int maxn = 1e6 + 6;
const int inf = ~(1u << 31u);
const ll linf = ~(1llu << 63u);
struct struc {
  int a = 3;
  int b;
} st;
int main() {
  // ios::sync_with_stdio(false);
  // // file(data);
  // int size = 1e1 + 3;
  // cout << "start:\n";
  // time_t t1 = clock();
  // for (int i = 0; i < 100000009; ++i) {
  //   bool x = (997 / 3 != 333);
  // }
  // time_t t2 = clock();
  // for (int i = 0; i < 100000009; ++i) {
  //   bool x = (997 != 333 * 3);
  // }
  // time_t t3 = clock();
  // cout << t2 - t1 << '\n' << t3 - t2 << endl;
  vector<pii> v(10);
  for (int i = 0; i < 10; ++i) {
    v[i].first = -i;
    v[i].second = -i;
  }
  sort(v.begin(), v.end(), [](pii &a, pii &b) { return a.first > b.first; });
  for (auto &i : v) {
    cout << i.first << ' ' << i.second << endl;
  }
  return 0;
}