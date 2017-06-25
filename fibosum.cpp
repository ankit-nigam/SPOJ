#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void multiply(long long f[2][2], long long m[2][2]){
  long long x =  (f[0][0] * m[0][0] + f[0][1] * m[1][0]) % mod;
  long long y =  (f[0][0] * m[0][1] + f[0][1] * m[1][1]) % mod;
  long long z =  (f[1][0] * m[0][0] + f[1][1] * m[1][0]) % mod;
  long long w =  (f[1][0] * m[0][1] + f[1][1] * m[1][1]) % mod;
  f[0][0] = x;
  f[0][1] = y;
  f[1][0] = z;
  f[1][1] = w;
}

void power(long long f[2][2], int y){
  if(y == 0 || y == 1){
    return;
  }
  long long m[2][2] = {{1, 1}, {1, 0}};
  power(f, y / 2);
  multiply(f, f);
  if(y % 2 != 0){
    multiply(f, m);
  }
}

long long fib(int y){
  long long f[2][2] = {{1, 1}, {1, 0}};
  if(y == 0){
    return 0;
  }
  power(f, y - 1);
  return f[0][0];
}

long long sum(int x){
  return fib(x + 2) - 1;
}

int main(){
  ios::sync_with_stdio(0);
  int x, y, tc;
  long long ans = 0;
  cin >> tc;
  for(int tt = 0; tt < tc; tt++){
    cin >> x >> y;
    ans = (sum(y) - sum(x - 1)) % mod;
    if(ans < 0){
      ans += mod;
    }
    ans %= mod;
    cout << ans << endl;
  }
  return 0;
}
