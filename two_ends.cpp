#include <bits/stdc++.h>

using namespace std;

int a[1010];
int dp[1010][1010];
int ans;

int best(int s, int e){
  if (s > e) {  
    return 0;
  }
  if (dp[s][e] == -1) {
    dp[s][e] = max(a[s] + (a[s + 1] >= a[e] ? best(s + 2, e) : best(s + 1, e - 1)), a[e] + (a[s] >= a[e - 1] ? best(s + 1, e - 1) : best(s, e - 2)));
  }
  return dp[s][e];
}

int main(){
  #ifdef HOME_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int n, tc = 1;
  scanf("%d", &n);
  while (n) { 
    int sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    for (int i = 0; i <= 1002; i++) {
      for (int j = 0; j <= 1002; j++) {
        dp[i][j] = -1;
      }
    }
    ans = 2 * (best(0, n - 1)) - sum;
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n", tc, ans);
    tc++;
    scanf("%d", &n);
  }
  return 0;
}     