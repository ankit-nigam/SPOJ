#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

ll dp[5010];

ll solve(string s, ll x) {
  if (dp[x] != -1) {
    return dp[x];
  }
  if ((s[x] - '0') == 0) {
    return 0;
  }
  if (x >= s.size() - 1) {
    dp[x] = 1;
    return 1ll;
  }
  if ((s[x] - '0') == 1) {
    if ((s[x + 1] - '0') == 0) {
      dp[x] = solve(s, x + 2);
      dp[x + 1] = 0;
    } else {
      dp[x] = solve(s, x + 1) + solve(s, x + 2);
    }
  } else if ((s[x] - '0') == 2) {
    if ((s[x + 1] - '0') > 6) {
      dp[x] = solve(s, x + 1);
    } else if ((s[x + 1] - '0') == 0) {
      dp[x] = solve(s, x + 2);
      dp[x + 1] = 0;
    } else {
      dp[x] = solve(s, x + 1) + solve(s, x + 2);
    }
  } else {
    if ((s[x + 1] - '0') == 0) {
      dp[0] = 0;
    } else {
      dp[x] = solve(s, x + 1);
    }
  }
  return dp[x];
}

int main() {
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  
  string s;
  cin >> s;
  while (s != "0") { 
    for (int i = 0; i < 5010; i++) {
      dp[i] = -1;
    }
    solve(s, 0ll);
    cout << dp[0] << "\n";
    cin >> s;
  }
  
  #ifdef HOME
    fprintf(stderr, "Time taken:- %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
    fflush(stderr);
  #endif
  return 0;
}   