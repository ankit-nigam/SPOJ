#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

int l[7010][7010];

int solve(string a, string b) {
  int lena = a.size();
  int lenb = b.size();
  for (int i = 0; i <= lena; i++) {
    for (int j = 0; j <= lenb; j++) {
      l[i][j] = 0;
    }
  }
  for (int i = 0; i <= lena; i++) {
    for (int j = 0; j <= lenb; j++) {
      if (i == 0 || j == 0) {
        l[i][j] = 0;
      } else if (a[i - 1] == b[j - 1]) {
        l[i][j] = 1 + l[i - 1][j - 1];
      } else {
        l[i][j] = max(l[i - 1][j], l[i][j - 1]);
      }
    }
  }
  return l[lena][lenb];
}

int main() {
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  
  int tc;
  scanf("%d", &tc);
  string a;
  for (int tt = 0; tt < tc; tt++) {
    cin >> a;
    string b = a;
    reverse(a.begin(), a.end());
    cout << b.size() - solve(a, b) << endl;
  }
  
  #ifdef HOME
    fprintf(stderr, "Time taken:- %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
    fflush(stderr);
  #endif
  return 0;
}