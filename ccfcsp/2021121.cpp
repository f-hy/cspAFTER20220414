#include <bits/stdc++.h>
using namespace std;
const int maxn = 201;
const int maxN = 1e7;
// 1<=n<=200,n<N<=1e7
int n, N, A[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> N;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  int j = 0;
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    if (A[j + 1] <= i && j < n) ++j;
    sum += j;
  }
  cout << sum << endl;
  return 0;
}