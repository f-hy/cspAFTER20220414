#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 1;
int n;  //<=100,B单调不降<=1e5
int b, ma = 0, mi = INT_MAX, sma, smi;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> b;
    if (b > ma) {
      ma = b;
      mi = min(mi, b);
      smi += ma;
    } else {
      mi = 0;
      smi += mi;
    }
    sma += b;
  }
  cout << sma << endl << smi << endl;
  return 0;
}