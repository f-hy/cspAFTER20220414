// https://blog.csdn.net/Sunnyztg/article/details/125646721
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

const int maxn = 1e3 + 3;
const int maxS = 5e1 + 1;
const ll maxL = 1e9 + 9;
int n;
ll L;
int S;
int num = 0;
vector<pll> vp(maxn);
map<ll, set<ll>> block;
int main() {
  cin >> n >> L >> S;
  ll x, y;
  for (int i = 0; i < n; ++i) {
    cin >> vp[i].first >> vp[i].second;
  }
  bool bl;
  for (int i = S; i >= 0; --i) {
    for (int j = 0; j <= S; ++j) {
      cin >> bl;
      if (bl) {
        ++num;
        block[i].insert(j);
      }
    }
  }
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    int tmp = 0;
    bool flag = true;
    for (int j = 0; j < n; ++j) {
      if (vp[j].first >= vp[i].first && vp[j].first <= vp[i].first + S &&
          vp[j].second >= vp[i].second && vp[j].second <= vp[i].second + S) {
        ++tmp;
      }
    }
    if (num == tmp) {  //宝藏数相同
      for (int j = 0; j <= S; ++j) {
        for (int k = 0; k <= S; ++k) {
          if (vp[i].first + j > L || vp[i].second + k > L) {
            flag = false;
            break;
          }
          if (block[j].find(k) == block[j].end()) {
            for (int m = 0; m < n; ++m) {
              if (vp[m].first == vp[i].first + j &&
                  vp[m].second == vp[i].second + k) {
                flag = false;
                break;
              }
            }
          } else {
            for (int m = 0; m < n; ++m) {
              if (vp[m].first == vp[i].first + j &&
                  vp[m].second == vp[i].second + k) {
                break;
              }
              if (m == n - 1) {
                flag = false;
              }
            }
          }
        }
      }
      if (flag) {
        ++res;
      }
    }
  }
  cout << res << endl;
  return 0;
}