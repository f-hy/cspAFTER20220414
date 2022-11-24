#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
int n;
int main() {
  cin >> n;
  vector<pii> dp(n);
  for (auto &i : dp) cin >> i.first >> i.second;
  //   sort(dp.begin(), dp.end(), [](pll &a, pll &b) { return a.first < b.first;
  //   });
  sort(dp.begin(), dp.end());
  priority_queue<int, vector<int>, greater<int> > pq;
  ll res = 0;
  for (auto &i : dp) {
    if (pq.size() < i.first) {
      res += i.second;
      pq.push(i.second);
    } else if (pq.top() < i.second) {
      res -= pq.top();
      pq.pop();
      pq.push(i.second);
      res += i.second;
    }
  }
  cout << res;
  return 0;
}