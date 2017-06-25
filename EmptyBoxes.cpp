#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int n, k, t, f, tc;
  cin >> tc;
  for(int tt = 0; tt < tc; tt++){
    cin >> n >> k >> t >> f;
    long long ans = (n + (f - n) * k / (k - 1));
    cout << ans << endl;
  }
  return 0;
}