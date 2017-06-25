#include <bits/stdc++.h>
 
using namespace std;

double ad[102][102];
 
int main() {
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int n, m, x, y, w;
  scanf("%d %d", &n, &m);
  while (n != 0) {
    memset(ad, 0, sizeof(ad)); 
    for (int i = 0; i < m; i++) {
      scanf("%d %d %d", &x, &y, &w);
      ad[x][y] = ad[y][x] = (w * 1.0 / 100.0);
    }
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          ad[i][j] = max(ad[i][j], ad[i][k] * ad[k][j]);
        }
      }
    }
    printf("%.6lf percent\n", ad[1][n] * 100.0 + 1e-10);
    scanf("%d %d", &n, &m); 
  }
  return 0;
} 