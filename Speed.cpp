#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
  return a ? gcd(b % a, a) : b;
}

int main(){
  ios::sync_with_stdio(0);
  int tc, x, y;
  cin >> tc;
  for(int tt = 0; tt < tc; tt++){
    cin >> x >> y;
    int ans = 0;
    ans = abs(x - y) / gcd(abs(x), abs(y));
    cout << ans << endl;
  }
  return 0;
}