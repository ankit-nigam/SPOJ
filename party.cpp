#include <bits/stdc++.h>

using namespace std;

int main(){
  #ifdef HOME_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int n, s;
  scanf("%d %d", &s, &n);
  while (s != 0 && n != 0) {
    int v[n + 1], w[n + 1];
    int dp[n + 1][s + 1];
    int cost = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &w[i], &v[i]); 
    }
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= s; j++) {
        if (i == 0 || j == 0) {
          dp[i][j] = 0;
        }
        else if (w[i - 1] <= j) {
          dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
        }
        else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    for (int i = 1; i <= s; i++) {
      if (dp[n][i] == dp[n][s]) {
        cost = i;
        break;
      }
    }
    printf("%d %d\n", cost, dp[n][s]);
    scanf("%d %d", &s, &n);
  }
  return 0;
} 