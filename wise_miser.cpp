#include <bits/stdc++.h>

using namespace std;

int dp[510][510];
int a[510][510] = {0};

int main(){
  ios::sync_with_stdio(0);                                  
  int n, m, ans = 10000000;
  cin >> n >> m; 
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
    }
  }
  for(int i = 0; i <= n + 1; i++){
    a[i][0] = a[i][m + 1] = 10000000;
  }
  for(int i = 1; i <= n + 1; i++){
    for(int j = 1; j <= m; j++){
      dp[i][j] = min(min(dp[i - 1][j - 1] + a[i - 1][j - 1], dp[i - 1][j] + a[i - 1][j]), dp[i - 1][j + 1] + a[i - 1][j + 1]); 
    }
  } 
  for(int i = 1; i <= m; i++){
    ans = min(ans, dp[n + 1][i]);
  } 
  cout << ans << endl;
  return 0;
}