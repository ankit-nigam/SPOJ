#include <bits/stdc++.h>
 
using namespace std;
 
#define max 10000
vector <int> a;
 
bool isprime(int n){
  if(n == 1){
    return false;
  }
  for(int i = 2; i <= sqrt(n); i++){
    if(n % i == 0){
      return false;
    }
  }
  return true;
}
 
void pre(){
  ios::sync_with_stdio(0);
  int count, x, d = 0;
  for(int i = 30; i <= max; i++){
    count = 0;
    x = i;
    for(int j = 2; j * j <= i; j++){
      if(x % j == 0){
        while(x % j == 0){
          x /= j;
        }
        count++;
      }
    }
    if(isprime(x)){
      count++;
    }
    if(count >= 3){
      a.push_back(i);
      d++;
      if(d == 1000){
        break;
      }
    }
  }
}
 
int main(){
  ios::sync_with_stdio(0);
  pre();
  int tc;
  cin >> tc;
  for(int tt = 0; tt < tc; tt++){
    int n;
    cin >> n;
    cout << a[n - 1] << endl;
  }
  return 0;
} 