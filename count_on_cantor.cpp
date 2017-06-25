#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  for(int tt = 0; tt < tc; tt++){
    int n, i, a, b;
    cin >> n;
    for(i = 1; i <= 10000; i++){
      if((i * (i + 1)) / 2 >= n){
        break;
      }
    }
    int dif = n - (i * (i - 1) / 2);
    i++;
    if(i % 2 == 0){
      a = i - dif;
      b = dif;
    } else{
      a = dif;
      b = i - dif;
    }
    cout << "TERM " << n << " IS " << a << "/" << b << endl;
  }      
  return 0;
}