#include <bits/stdc++.h>

using namespace std;

int v[2010], w[2010];
int dp[2010][2010];

int main(){
  #ifdef HOME_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
    int s, n;
  scanf("%d %d", &s, &n);
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
  printf("%d\n", dp[n][s]);
  return 0;
} 