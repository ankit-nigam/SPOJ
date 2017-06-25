#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int n, ans = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    ans ^= num;
  }
  cout << ans << endl;
  return 0;
}