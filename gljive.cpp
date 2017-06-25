#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int sum = 0, a[15], s = 1000000, ans;
  vector <int> c;
  for(int i = 0; i < 10; i++){
    cin >> a[i];
  }
  for(int i = 0; i < 10; i++){
    sum += a[i];
    if(abs(sum - 100) <= s){
      ans = sum;
      s = abs(sum - 100);
    }
  }
  cout << ans << endl;
  return 0;
} 