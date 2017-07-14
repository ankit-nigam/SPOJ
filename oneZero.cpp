#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

int dp[20010][2], last[20010][2];
stack <int> ans;

void solve(int n) {
  queue <pair <int, int> > q;
  int len = 0;
  for (int i = 0; i < 20010; i++) {
    for (int j = 0; j < 2; j ++) {
      dp[i][j] = -1;
      last[i][j] = -1;
    }
  }
  q.push(make_pair(1 % n, 1));
  dp[1 % n][1] = 0;
  while (!q.empty()) {
    pair <int, int> v = q.front();
    q.pop();
    int rem = v.first;
    int dig = v.second;
    if (rem == 0) {
      ans.push(dig);
      break;
    }
    for (int i = 0; i < 2; i++) {
      int x = (rem * 10 + i) % n;
      if (dp[x][i] != -1) {
        continue;
      }
      dp[x][i] = rem;
      last[x][i] = dig;
      q.push(make_pair(x, i));
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
    int x = 0, y = ans.top();
    while (true) {
      if (x == 1 && y == 1) {
        break;
      }
      ans.push(last[x][y]);
      int xx = dp[x][y];
      int yy = last[x][y];
      x = xx; y = yy;
    }
    while (!ans.empty()) {
      cout << ans.top();
      ans.pop();
    }
    cout << "\n";
  }
  
  #ifdef HOME
    fprintf(stderr, "Time taken:- %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
    fflush(stderr);
  #endif
  return 0;
}   