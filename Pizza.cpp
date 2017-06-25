#include <bits/stdc++.h>

using namespace std;

int main(){
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  int n, x = 0, y = 0, z = 0;
  int ans = 1;
  string s;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    cin >> s;
    if(s[0] == '1' && s[2] == '4'){
      x++;
    }
    else if(s[0] == '1' && s[2] == '2'){
      y++;
    }
    else {
      z++;
    }
  }
  if(z < x){
    ans += z;
    x -= z;
    z = 0;
  } else if(z == x){
    ans += z;
    x = 0;
    z = 0;
  } else if(z > x){
    ans += z;
    x = 0;
  }
  ans += (y / 2);
  if(y % 2){
    ans++;
    if(x == 1) x--;
    if(x > 1) x -= 2;
  }
  ans += (x / 4);
  if(x % 4){
    ans++;
  }
  printf("%d", ans);
  return 0;
}