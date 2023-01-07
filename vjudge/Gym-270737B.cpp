#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
string s;

int n, a[maxn], Sum[4], cnt[4];
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'Q')
      ++Sum[0], a[i] = 0;
    else if (s[i] == 'W')
      ++Sum[1], a[i] = 1;
    else if (s[i] == 'E')
      ++Sum[2], a[i] = 2;
    else if (s[i] == 'R')
      ++Sum[3], a[i] = 3;
  }
  int res = s.length(), l = 0;
  bool flag;
  for (int i = 0; i < s.length(); ++i) {
    ++cnt[a[i]];
    while (l <= i + 1) {
      flag = true;
      for (int j = 0; j < 4; ++j)
        if (Sum[j] - cnt[j] > s.length() / 4) flag = false;
      if (!flag) break;
      res = min(res, i - l + 1);
      --cnt[a[l++]];
    }
  }
  cout << res << endl;
  return 0;
}