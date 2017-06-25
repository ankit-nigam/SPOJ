#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int tc;
  string s;
  cin >> tc;
  for (int t = 0; t < tc; t++) {
    bool bad = false;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len / 2; i++) {
      if (s[i] != s[len - i - 1]) {
        printf("NO\n");
        bad = true;
        break;
      }
    }
    if (bad) {
      continue;
    }
    printf("YES\n");
  }
  return 0;
} 