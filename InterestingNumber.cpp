#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

int dp[1010][1010], last[1010][1010], mod[1010][1010];
stack <int> ans;

int main() {
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  
  int tc, n;
  scanf("%d", &tc);
  for (int tt = 0; tt < tc; tt++) {
    int dsum = 0, rem = 0, x, y;
    queue <pair <int, int> > q;
    scanf("%d", &n);
    for (int i = 0; i < 1010; i++) {
      for (int j = 0; j < 1010; j++) {
        dp[i][j] = -1;
        mod[i][j] = 0;
        last[i][j] = 0;
      }
    }
    for (int i = 1; i <= 9; i++) {
      q.push(make_pair(i % n, i));
      dp[i % n][i] = i;
      last[i % n][i] = i;
    }
    while (!q.empty()) {
      pair<int, int> v = q.front();
      dsum = v.second;
      rem = v.first;
      q.pop();
      if (dsum == n && rem == 0) {
        break;
      }
      for (int i = 0; i <= 9; i++) {
        x = (rem * 10 + i) % n;
        y = dsum + i;
        if (dp[x][y] != -1 || y > n) {
          continue;
        }
        q.push(make_pair(x, y));
        dp[x][y] = y;
        last[x][y] = i;
        mod[x][y] = rem;
      }
    }
    x = 0, y = n;
    while (true) {
      if (x == 0 && y == 0) {
        break;
      }
      ans.push(last[x][y]);
      int a = mod[x][y];
      int b = (dp[x][y] - last[x][y]);
      x = a; y = b;
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