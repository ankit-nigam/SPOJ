#include <bits/stdc++.h>

using namespace std;

int main(){
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  string s;
  getline(cin, s);
  while (s[0] != '*') {
    int x = (int) s[0];
    int y;
    if (x > 90) {
      y = x - 32;
    } else {
      y = x + 32;
    }
    bool bad = false;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == ' ') {
        int m = (int) s[i + 1];
        if (m != x && m != y) {
          puts("N");
          bad = true;
          break;
        }
      }
    }
    if (bad) {
      getline(cin, s);
      continue;
    } else {
      puts("Y");
    }
    getline(cin, s);
  }
  return 0;
}