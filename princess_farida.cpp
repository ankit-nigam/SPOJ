#include <bits/stdc++.h>

using namespace std;

long long dp[100010], a[100010];

int main(){
  ios::sync_with_stdio(0);
  int tc, n;
  cin >> tc;
  for(int t = 0; t < tc; t++){
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    for(int i = 2; i < n; i++){
      dp[i] = max(dp[i - 2] + a[i], dp[i - 1]);
    }
    printf("Case %d: %lld\n", t + 1, dp[n - 1]);
  }
  return 0;
}