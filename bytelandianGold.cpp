#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

ll dp[200010];

ll solve(ll n) {
  if ((n < 200010) && (dp[n] != -1)) {
    return dp[n];
  }
  return max(n, solve(n / 2) + solve(n / 3) + solve(n / 4));
}

void pre() {  
  for (int i = 0; i < 200010; i++) {
    dp[i] = -1;
  }
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  for (int i = 4; i < 200010; i++) {
    dp[i] = solve(i);
  }
}
 
int main() {
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  
  pre();
  ll n;
  while (cin >> n) {
    if (n < 200010) {
      cout << dp[n] << endl;
      continue;
    }
    cout << solve(n) << endl;
  }
   
  #ifdef HOME
    fprintf(stderr, "Time taken:- %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
    fflush(stderr);
  #endif
  return 0;
} 