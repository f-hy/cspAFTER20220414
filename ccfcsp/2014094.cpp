#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

const int maxn = 1e3 + 3;
int n, m, k, d;
int dis[maxn][maxn], need[maxn][maxn];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
ll res;
void bfs() {
  queue<pii> q;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      if (!dis[i][j]) q.push({i, j});  //将所有源点加入队列中
  while (!q.empty()) {
    pii u = q.front();
    q.pop();
    for (int i = 0; i < 4; ++i) {
      int x = u.first + dx[i];
      int y = u.second + dy[i];
      if (dis[x][y] ==
          INT_MAX) {  //只有dis为MAX的点才是未被访问的，源点和网格外的点为0，障碍点为-1
        dis[x][y] = dis[u.first][u.second] + 1;
        res += dis[x][y] * 1ll * need[x][y];
        q.push({x, y});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k >> d;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dis[i][j] =
          INT_MAX;  //将所有节点初始值设置为MAX，方便之后存放答案和判断是否被访问
    }
  }
  int x, y, c;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    dis[x][y] = 0;
  }
  for (int i = 0; i < k; ++i) {
    cin >> x >> y >> c;
    need[x][y] += c;
  }
  for (int i = 0; i < d; ++i) {
    cin >> x >> y;
    dis[x][y] = -1;  //不可访问节点设置dis为-1，在bfs中不会被访问到
  }
  bfs();
  cout << res;
  return 0;
}