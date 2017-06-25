#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

typedef long long ll;

int p[100010];

int mul(ll a, ll b){
  return a * b % mod;
}

ll power(int a, int b){
  ll res = 1;
  while(b > 0){
    if(b & 1){
      res = mul(res, (ll) a);
    }
    b >>= 1;
    a = mul(a, a);
  }
  return res;
}

int main(){
  ios::sync_with_stdio(0);
  int tc, a, b, k;
  cin >> tc;
  for(int tt = 0; tt < tc; tt++){
    ll ans = 0;
    ll m;
    cin >> a >> b >> k;
    for(int i = 1; i <= b; i++){
      p[i] = power(i, k);
    }
    for(int i = 1; i <= b; i++){
      m = (b / i) - (a / i);
      if(a % i == 0){
        m++;
      }
      ans += mul(m, p[i]);
    }
    cout << ans % mod << endl;
  }
  return 0;
}