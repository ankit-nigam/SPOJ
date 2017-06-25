#include <bits/stdc++.h>

using namespace std;

string a, b, c, d, e;

int get(string x){
  int res = 0;
  int d = x.size() - 1;
  for(int i = 0; i < x.size(); i++){
    res += (x[i] - '0') * pow(10, d);
    d--;
  }
  return res;
}

void getm(string x, int a, int b, bool ok){
  int dif = b - a;
  if(ok){
    dif = a + b;
  }
  string s = "";
  while(dif > 0){
    s += (dif % 10) + '0';
    dif /= 10;
  }
  for(int i = s.size() - 1; i >= 0; i--){
    cout << s[i];
  }                
}

int main(){
  ios::sync_with_stdio(0);
  int tc;
  scanf("%d", &tc);
  for(int t = 0; t < tc; t++){
    cin >> a >> d >> b >> e >> c;
    int x, y, z;
    for(int i = 0; i < a.size(); i++){
      if(a[i] == 'm'){
        y = get(b);
        z = get(c);
        getm(a, y, z, false);
        cout << " + " << y << " = " << z << endl;
        break;
      }
    }
    for(int i = 0; i < b.size(); i++){
      if(b[i] == 'm'){
        x = get(a);
        z = get(c);
        cout << x << " + ";
        getm(b, x, z, false);
        cout << " = " << z << endl;
        break;
      }
    }
    for(int i = 0; i < c.size(); i++){
      if(c[i] == 'm'){
        y = get(b);
        x = get(a);
        cout << x << " + " << y << " = ";
        getm(c, x, y, true);
        cout << endl;
        break;
      }
    }
  }
  return 0;
}                      