#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
char a[30][30];
int dist[30][30], dp[30][30], n, m;
queue < pair <int, int> > q;
pair <int, int> st, dest;
 
void solve() {
  int x = st.first, y = st.second;
  q.push(make_pair(x, y));
  dp[x][y] = 0;
  while (!q.empty()) {
    pair <int, int> v = q.front();
    x = v.first;
    y = v.second;
    q.pop();
    if (x + 1 <= n && (dp[x + 1][y] > dp[x][y] + dist[x + 1][y]) && a[x + 1][y] != 'X') {
      q.push(make_pair(x + 1, y));
      dp[x + 1][y] = dp[x][y] + dist[x + 1][y];
    }
    if (x - 1 >= 1 && (dp[x - 1][y] > dp[x][y] + dist[x - 1][y]) && a[x - 1][y] != 'X') {
      q.push(make_pair(x - 1, y));
      dp[x - 1][y] = dp[x][y] + dist[x - 1][y];
    }
    if (y + 1 <= m && (dp[x][y + 1] > dp[x][y] + dist[x][y + 1]) && a[x][y + 1] != 'X') {
      q.push(make_pair(x, y + 1));
      dp[x][y + 1] = dp[x][y] + dist[x][y + 1];
    }
    if (y - 1 >= 1 && (dp[x][y - 1] > dp[x][y] + dist[x][y - 1]) && a[x][y - 1] != 'X') {
      q.push(make_pair(x, y - 1));
      dp[x][y - 1] = dp[x][y] + dist[x][y - 1];
    }
  }
}
 
int main() {
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  
  cin >> m >> n;
  while (m > 0 && n > 0) {
    for (int i = 0; i < 30; i++) {
      for (int j = 0; j < 30; j++) {
        dist[i][j] = 1e9;
        dp[i][j] = 1e9;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'S') {
          dist[i][j] = 0;
          st.first = i;
          st.second = j;
        } else if (a[i][j] == 'D') {
          dist[i][j] = 0;
          dest.first = i;
          dest.second = j;
        } else if (a[i][j] == 'X') {
          dist[i][j] = 1e9;
        } else {
          dist[i][j] = a[i][j] - '0';
        }
      }
    }
    solve();
    cout << dp[dest.first][dest.second] << endl;
    cin >> m >> n;
  }  
  
  #ifdef HOME
    fprintf(stderr, "Time taken:- %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
    fflush(stderr);
  #endif
  return 0;
} 