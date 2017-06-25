#include <bits/stdc++.h>

using namespace std;

char b[300];

int gcd(int a, int b){
  return a ? gcd(b % a, a) : b;
}

int get(int a){
  int res = 0;
  for(int i = 0; b[i] != '\0'; i++){
    res = ((b[i] - '0') + res * 10) % a;
  }
  return res;
}

int main(){
  #ifdef HOME_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int tc, a;
  cin >> tc;
  for(int t = 0; t < tc; t++){
    cin >> a >> b;
    if(a == 0){
      cout << b << endl;
      continue;
    }
    int res = get(a);
    cout << gcd(res, a) << endl;
  }
  return 0;
}