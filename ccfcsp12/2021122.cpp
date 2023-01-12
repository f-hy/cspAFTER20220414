// https://blog.csdn.net/victory066/article/details/125897928
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 1;
const int maxN = 1e9;
int n, N, A[maxn + 1], den;
ll getg(int l, int r) {  //求g[l] + g[l+1] + ... + g[r]
  if (l / den == r / den) return (ll)(l / den) * (r - l + 1);  //同行
  int b = l / den + 1, e = r / den - 1;
  ll res = (b - 1) * (ll)(b * den - l);            // left
  res += (e + 1) * (ll)(r - (e * den + den) + 1);  // right
  res += (ll)(e - b + 1) * (b + e) / 2 * den;      // mid,等差数列求和
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> N;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  A[n + 1] = N;
  ll error = 0;       // must be ll, or be wrong
  den = N / (n + 1);  // denominator
  for (int i = 0; i <= n; ++i) {
    int l = A[i], r = A[i + 1] - 1;
    if (i >= r / den || i <= l / den) {  //在两侧
      error +=
          abs((ll)(r - l + 1) * i - getg(l, r));  // error +=|sum(fx)-sum(gx)|
    } else {                                      //相交
      int mid = i * den;                          //能够让gx=i的最小值
      error += abs((ll)(mid - l + 1) * i - getg(l, mid));  // left
      error += abs((ll)(r - mid + 1) * i - getg(mid, r));  // right
      // error += abs((ll)(r - mid) * i - getg(mid + 1, r));
    }
  }
  /*
  // failed,why?
  for (int i = 1; i <= n; ++i) {  // f(i)=i,
    int num = A[i + 1] - A[i];    //同段，A[i+1]>A[i]，sum>0
    int beg = den - A[i] % den;   //段头长, 1~den
    int gb = A[i] / den;
    error = error + beg * abs(gb - i);
    num -= beg;
    if (num > 0) {
      int end = A[i + 1] % den;  // 0~den-1
      int ge = (A[i + 1] - 1) / den;
      error = error + end * abs(ge - i);
      num -= end;
      if (num > 0) {
        if (end == 0) {
          ge += 1;
        }
        for (int g = gb + 1; g < ge; ++g) {
          error = error + den * abs(g - i);
        }
      }
    }
  }  */
  cout << error << endl;
  return 0;
}