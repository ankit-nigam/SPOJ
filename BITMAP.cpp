#include <bits/stdc++.h>
 
using namespace std;

char a[200][200];
int dis[200][200];
int n, m;
bool done[200][200];

void bfs(queue <pair <int, int> > &q) { 
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (x + 1 <= n && !done[x + 1][y]) {
      q.push(make_pair(x + 1, y));
      done[x + 1][y] = true;
      dis[x + 1][y] = dis[x][y] + 1;
    }
    if (x - 1 >= 1 && !done[x - 1][y]) {
      done[x - 1][y] = true;
      q.push(make_pair(x - 1, y));
      dis[x - 1][y] = dis[x][y] + 1;
    }
    if (y + 1 <= m && !done[x][y + 1]) {
      done[x][y + 1] = true;
      q.push(make_pair(x, y + 1));
      dis[x][y + 1] = dis[x][y] + 1;
    }
    if (y - 1 >= 1 && !done[x][y - 1]) {
      q.push(make_pair(x, y - 1));
      done[x][y - 1] = true;
      dis[x][y - 1] = dis[x][y] + 1;
    }
  }
}
 
int main() {
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int tc;
  scanf("%d", &tc);
  for (int tt = 0; tt < tc; tt++) {
    queue <pair <int, int> > q;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n + 1; i++) {
      for (int j = 1; j <= m + 1; j++) {
        dis[i][j] = 1e9;
      }
    }
    memset(done, false, sizeof done);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        if (a[i][j] == '1') {
          dis[i][j] = 0;
          done[i][j] = true;
          q.push(make_pair(i, j));
        }
      }
    }
    bfs(q);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << dis[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}