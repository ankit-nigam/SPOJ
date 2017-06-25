#include <bits/stdc++.h>

using namespace std;

const int mod = 10000007;

int mul(int a, int b){
  return (long long) a * b % mod;
}

int power(int a, int b){
  int res = 1;
  while(b > 0){
    if(b & 1){
      res = mul(res, a);
    }
    b >>= 1;
    a = mul(a, a);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  while(n || k){
    long long ans = 2 * (power(n - 1, k) + power(n - 1, n - 1)) + power(n, n) + power(n, k);
    cout << ans % mod << endl;
    cin >> n >> k;
  } 
  return 0;
}
  