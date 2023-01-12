// 障碍物并不是每时每刻都存在的，而是只在一个连续的区间存在
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 2;  // r,c,n,m,a,b
const int maxt = 1e4 + 4;  // t是t行rcab数
const int mt = 3 * maxn;   // why?
int n, m, t;
bool vis[maxn][maxn][mt];
int b[maxn][maxn], e[maxn][maxn];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
struct node {
  int x, y, t;
  node(int x, int y, int t) : x(x), y(y), t(t) {}
};
int bfs() {
  queue<node> q;
  q.push(node(1, 1, 0));  //初始情况为在源点，时间为0
  vis[1][1][0] = true;
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int x = u.x + dx[i];
      int y = u.y + dy[i];
      if (x < 1 || x > n || y < 1 || y > m) continue;  //界限外不予考虑
      int t = u.t + 1;
      if (b[x][y] && t >= b[x][y] && t <= e[x][y])
        continue;  //判断点在时刻t时是否为不可通行点
      if (vis[x][y][t]) continue;      //同时间地点抵达过不予考虑
      if (t >= mt) continue;           //超过时间不予考虑
      if (x == n && y == m) return t;  //到达指定点
      vis[x][y][t] = true;
      q.push(node(x, y, t));
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> t;
  int r, c;
  for (int i = 0; i < t; ++i) {
    cin >> r >> c;
    cin >> b[r][c] >> e[r][c];
  }
  cout << bfs();
  return 0;
}