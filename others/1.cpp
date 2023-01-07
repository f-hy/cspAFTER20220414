#include <bits/stdc++.h>

using namespace std;

int main() {
  int x1 = 13, x2 = 13, k = 25;
  int y1 = 23, y2 = 23;
  for (int i = 0; i < 24; i++) {
    int f;
    int x3, y3;
    if (i == 0) {
      f = (3 * pow(x1, 2) + 4) / (2 * y1);
      cout << f << endl;
    } else {
      f = (y2 - y1) / (x2 - x1);
    }
    f %= 29;
    while (f < 0) f += 29;
    x3 = (pow(f, 2) - x1 - x2);
    y3 = (f * (x1 - x3) - y1);
    while (x3 < 0) {
      x3 += 29;
    }
    while (y3 < 0) {
      y3 += 29;
    }
    x1 = x3 % 29;
    y1 = y3 % 29;
    cout << x1 << ' ' << y1 << endl;
  }
  cout << x1 << " " << y1 << "\n";
  cout << -3 % 5 << '\n';
  return 0;
}
