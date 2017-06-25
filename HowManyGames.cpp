#include <bits/stdc++.h>
 
using namespace std;

int gcd(int a, int b){
  return a ? gcd(b % a, a) : b;
}

int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = a * res;
    }
    b >>= 1;
    a = a * a;
  }
  return res;
}
 
int main(){
  #ifdef HOME_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int tc;
  string s;
  cin >> tc;
  for (int t = 0; t < tc; t++) {
    int d = 0;
    cin >> s;
    bool yes = false;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] != '.') {
        d++;
      } else {
        yes = true;
        break;
      }
    }
    int res = 0;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] != '.') {
        res = ((s[i] - '0') + res * 10);
      }
    }
    int x = 1;
    if (yes) {
      x = power(10, d);
    }
    cout << x / gcd(x, res) << endl;
  }
  return 0;
}