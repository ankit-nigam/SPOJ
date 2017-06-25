#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int tc, r;
  cin >> tc;
  for(int t = 0; t < tc; t++){
    cin >> r;
    printf("Case %d: %.2f\n", t + 1, 4 * r * r + 0.25);
  }      
  return 0;
}