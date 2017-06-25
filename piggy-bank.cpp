#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int main(){
  #ifdef HOME_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int tc, in, fi, n;
  scanf("%d", &tc);
  for (int tt = 0; tt < tc; tt++) {
    scanf("%d %d", &in, &fi);
    int tw = fi - in;
    scanf("%d", &n);
    int dp[n + 2][tw + 2];
    int v[n + 2], w[n + 2];
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &v[i], &w[i]);
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= tw; j++) { 
        dp[i][j] = INF;
      }
    }
    int d = 1;
    for (int i = w[0]; i <= tw; i += w[0]) {
      dp[1][i] = d * v[0];
      d++;
    }
    for (int i = 1; i <= n + 1; i++) {
      dp[i][0] = 0;
    }
    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= tw; j++) {
        if (w[i - 1] <= j) {
          dp[i][j] = min(v[i - 1] + dp[i][j - w[i - 1]], dp[i - 1][j]);
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    if (dp[n][tw] < INF) {
      printf("The minimum amount of money in the piggy-bank is %d.\n", dp[n][tw]);
    } else {
      printf("This is impossible.\n");
    }
  }
  return 0;
}     