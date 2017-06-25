#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int tc, n, m;
  cin >> tc;
  for(int t = 0; t < tc; t++){
    cin >> n >> m;
    if(m == n){
      if(m % 2 == 0){
        cout << "L" << endl;
        continue;
      }else {
        cout << "R" << endl;
        continue;
      }
    }
    int x = min(n, m);
    if(x % 2 == 0){
      if(n > m){
        cout << "U" << endl;
        continue;
      } else{
        cout << "L" << endl;
        continue;
      }
    } else{
      if(n > m){
        cout << "D" << endl;
        continue;
      } else{
        cout << "R" << endl;
        continue;
      }
    }
  }    
  return 0;
}  