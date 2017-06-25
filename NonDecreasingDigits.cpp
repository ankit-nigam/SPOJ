#include <bits/stdc++.h>

using namespace std;

long long dp[65][11];
long long ans[65];

int main(){
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int tc, m, n;
  scanf("%d", &tc);
  long long sum = 0;
  ans[1] = 10;
  for (int i = 0; i < 10; i++) {
    dp[2][i] = 10 - i;
    sum += dp[2][i];
    ans[2] += dp[2][i];
  }
  for (int i = 3; i <= 64; i++) {
    for (int j = 0; j < 10; j++) {
      if (j == 0) {
        dp[i][j] = sum;
        continue;
      }
      dp[i][j] = sum - dp[i - 1][j - 1];
      sum = dp[i][j];
    }
    sum = 0;
    for (int j = 0; j < 10; j++) {
      sum += dp[i][j];
      ans[i] += dp[i][j];
    }
  }
  for (int tt = 0; tt < tc; tt++) {
    scanf("%d %d", &m, &n);   
    printf("%d %lld\n", m, ans[n]);
  }
  return 0;
}