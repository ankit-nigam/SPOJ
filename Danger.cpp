#include <bits/stdc++.h>

using namespace std;

int get(string b){
  int res = (b[0] - '0') * 10 + (b[1] - '0');
  res *= pow(10, (b[3] - '0'));
  return res;
}

int main(){
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  string s, x = "00e0";
  cin >> s;
  while(s != x){  
    int x = get(s);
    if(x == 3){
      printf("3\n");
      cin >> s;
      continue;
    }
    if(x <= 2){
      printf("1\n");
      cin >> s;
      continue;
    }
    int a = floor(log2(x));
    a = x - pow(2, a);
    cout << 2 * a + 1 << endl;
    cin >> s;
  }
  return 0;
}