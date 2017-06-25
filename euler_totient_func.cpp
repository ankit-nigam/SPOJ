#include <bits/stdc++.h>
 
using namespace std;
 
int phi(int n){
  int res = n;
  for(int i = 2; i * i <= n; i++){
    if(n % i == 0) res -= res / i;
    while(n % i == 0) n = n / i;
  }
  if(n > 1) res -= res / n;
  return res;
}
 
int main(){
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  for(int i = 0; i < tc; i++){
    int n;
    cin >> n;
    cout << phi(n) << endl;
  }
  return 0;
} 