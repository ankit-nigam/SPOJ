#include <bits/stdc++.h>

using namespace std;

int a[101], op[3], dp[1000010];

int main(){
  #ifdef HOME_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int k, l, m, ma = 0;
  scanf("%d %d %d", &k, &l, &m);
  op[0] = 1;
  op[1] = min(k, l);
  op[2] = max(k, l);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
    ma = max(a[i], ma);
  }
  for (int i = 0; i <= 1000001; i++) {
    dp[i] = -1;
  }
  dp[1] = dp[k] = dp[l] = 1;
  for (int i = 1; i <= ma; i++) {
    if (dp[i] == -1) {
      for (int j = 0; j < 3 && (op[j] < i); j++) {
        if (dp[i - op[j]] + 1 % 2 == 1) {
          dp[i] = 1;
          break;
        }
        dp[i] = 0;
      }
    }
  }
  for (int i = 0; i < m; i++) { 
    if (dp[a[i]]) {
      printf("A");
    } else {
      printf("B");
    }
  }
  return 0;
}