#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

int main(){
  ios::sync_with_stdio(0);
  ll n;
  cin >> n;
  while(n != 0){
    if(n == 1){ 
      cout << n << "^" << 1;
      cin >> n;
      continue;
    }
    int cnt = 0;
    for(ll i = 2; i * i <= n; i++){
      if(n % i == 0){
        cnt = 0;
        while(n % i == 0){
          n /= i;
          cnt++;
        }
        cout << i << "^" << cnt << " ";
      } 
    }
    if(n > 1){
      cout << n << "^" << 1;
    }
    cout << endl;
    cin >> n;
  }
  return 0;
}