#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int tc, n, x, y, ans = 0;
  cin >> tc;
  for(int tt = 0; tt < tc; tt++){
    ans = 0;
    cin >> n;
    pair <int, int> p[n + 1];
    vector <int> v;
    for(int i = 0; i < n; i++){
      cin >> x >> y;
      v.push_back(x);
      v.push_back(y);
      p[i] = make_pair(x, y);
    }
    x = 0; y = 1e8;
    for(int i = 0; i < (n + n); i++){
      int d = 0;
      for(int j = 0; j < n; j++){
        if(v[i] >= p[j].first && v[i] <= p[j].second){
          d++;
        }
      }
      ans = max(ans, d);
    }
    cout << ans << endl;
  }
  return 0;
}