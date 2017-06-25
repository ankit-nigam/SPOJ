#include <bits/stdc++.h>

using namespace std;

int dis[150][150];

void explore(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}

int main(){
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int n, e, m, t, x, y, w;
  scanf("%d %d %d %d", &n, &e, &t, &m);
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= n + 1; j++) {
      dis[i][j] = 1e9;
    }
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &x, &y, &w);
    dis[x][y] = w;
  }
  explore(n);
  dis[e][e] = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (dis[i][e] <= t) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}