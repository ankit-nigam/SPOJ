#include <bits/stdc++.h>

using namespace std;

int a[2010], n;
int dp[2010][2010];

int solve(int s, int e){
  if(s > e) {
    return 0;
  }
  int day = n - (e - s);
  if (dp[s][e] == -1) {
    dp[s][e] = max(a[s] * day + solve(s + 1, e), a[e] * day + solve(s, e - 1));
  }
  return dp[s][e];
}

int main(){
  #ifdef HOME_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i <= 2001; i++) {
    for (int j = 0; j <= 2001; j++) {
      dp[i][j] = -1;
    }
  }
  printf("%d\n", solve(1, n));
  return 0;
}     