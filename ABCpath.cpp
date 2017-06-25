#include <bits/stdc++.h>

using namespace std;

int a[60][60];
int done[60][60];
int ans = 0;

void dfs(int x, int y, int l){
  done[x][y] = true;
  ans = max(ans, l);
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      if (a[i][j] == a[x][y] + 1 && !done[i][j]) {
        dfs(i, j, l + 1);
      }
    }
  }
}

int main(){
  #ifdef HOME_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int n, m, tc = 1;
  scanf("%d %d", &n, &m);
  while (n != 0 && m != 0) {
    char c;
    ans = 0;
    memset(a, 0, sizeof a);
    memset(done, false, sizeof done);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> c;
        a[i][j] = c - '0';
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == 17) {
          dfs(i, j, 1);
        }
      }
    }
    printf("Case %d: %d\n", tc, ans);
    tc++;
    scanf("%d %d", &n, &m);
  }
  return 0;
}     