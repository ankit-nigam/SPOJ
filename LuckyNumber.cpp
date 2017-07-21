#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

int dp[10010][10], last[10010][10];
stack <int> ans;
bool okay;

void solve(int n) {
  okay = false;
  queue <pair <int, int> > q;
  q.push(make_pair(6 % n, 6));
  q.push(make_pair(8 % n, 8));
  for (int i = 0; i < 10010; i++) {
    for (int j = 0; j < 10; j++) {
      dp[i][j] = -1;
      last[i][j] = -1;
    }
  }
  while (!q.empty()) {
    pair <int, int> v = q.front();
    q.pop();
    int rem = v.first;
    int dig = v.second;
    if (rem == 0) {
      okay = true;
      ans.push(dig);
      break;
    }
    if (dig == 6) {
      int x = (rem * 10 + 6) % n;
      if (dp[x][6] == -1) {
        q.push(make_pair(x, 6));
        dp[x][6] = rem;
        last[x][6] = dig;
      }
    } else {
      int x = (rem * 10 + 6) % n;
      int y = (rem * 10 + 8) % n;
      if (dp[x][6] == -1) {
        q.push(make_pair(x, 6));
        dp[x][6] = rem;
        last[x][6] = dig;
      }
      if (dp[y][8] == -1) {
        q.push(make_pair(y, 8));
        dp[y][8] = rem;
        last[y][8] = dig;
      }
    }
  }
}

int main() {
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  
  int tc, n;
  scanf("%d", &tc);
  for (int tt = 0; tt < tc; tt++) {
    scanf("%d", &n);
    solve(n);
    if (!okay) {
      printf("-1\n");
      continue;
    }
    int xx = 0, yy = ans.top();
    while (true) {
      if (last[xx][yy] == -1) {
        break;
      }
      ans.push(last[xx][yy]);
      int x = dp[xx][yy];
      int y = last[xx][yy];
      xx = x; yy = y;
    }
    while (!ans.empty()) {
      printf("%d", ans.top());
      ans.pop();
    }
    printf("\n");
  }
  
  #ifdef HOME
    fprintf(stderr, "Time taken:- %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
    fflush(stderr);
  #endif
  return 0;
}