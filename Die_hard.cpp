#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];

int solve(int x, int y){
  if(x <= 0 || y <= 0){
    return 0;
  }
  if(dp[x][y] == -1){
    dp[x][y] = max(solve(x - 17, y + 7) + 2, solve(x - 2, y - 8) + 2);
  }
  return dp[x][y];
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int tc, h, a;
  scanf("%d", &tc);
  for(int tt = 0; tt < tc; tt++){
    scanf("%d %d", &h, &a);
    for(int i = 0; i <= 1001; i++){
      for(int j = 0; j <= 1001; j++){
        dp[i][j] = -1;
      }
    }
    int ans = solve(h, a);
    ans--;
    printf("%d\n", ans);
  }
  return 0;
}