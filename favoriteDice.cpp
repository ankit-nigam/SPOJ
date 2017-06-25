#include <bits/stdc++.h>

using namespace std;

int main(){
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int tc, n;
  cin >> tc;
  for (int i = 0; i < tc; i++) {
    cin >> n;
    cout << fixed << setprecision(2);
    float ans = 0.0;
    for (int i = 1; i < n; i++) {
      ans += (1.0 / (i * 1.0));
    }
    ans *= (n * 1.0);
    cout << ans + 1 << endl;
  }
  return 0;
}