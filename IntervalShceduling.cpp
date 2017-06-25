#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int tc, n, x, y, ans = 0;
  cin >> tc;
  for(int tt = 0; tt < tc; tt++){
    ans = 1;
    cin >> n;
    pair <int, int> p[n + 1];
    for(int i = 0; i < n; i++){
      cin >> x >> y;
      p[i] = make_pair(y, x);
    }
    sort(p, p + n);
    x = p[0].second;
    y = p[0].first;
    for(int i = 1; i < n; i++){
      if(p[i].second >= y){
        ans++;
        y = p[i].first;
      }
    }
    cout << ans << endl;
  }
  return 0;
}   