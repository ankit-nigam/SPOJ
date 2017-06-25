#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int tc, n;
  cin >> tc;
  string c[8] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
  for(int t = 0; t < tc; t++){
    int ans[8] = {0};
    cin >> n;     
    string s;
    cin >> s;
    for(int i = 0; i < 38; i++){
      string b = "";
      b += s[i];
      b += s[i + 1];
      b += s[i + 2];
      for(int j = 0; j < 8; j++){
        if(b == c[j]){
          ans[j]++;
          break;
        }
      }
    }
    cout << n << " ";
    for(int i = 0; i < 8; i++){
      cout << ans[i] << " ";
    }
    cout << endl;
  }      
  return 0;
}