#include <bits/stdc++.h>

using namespace std;

void solve(string x){
  int res = 0;
  stack <char> s;
  for(int i = 0; i < x.size(); i++){
    if(x[i] == '{'){  
      s.push(x[i]);
    } else{
      if(s.empty()){
        s.push('{');
        res++;
      } else if(s.top() == '{'){
        s.pop();
      }
    }
  }
  cout << res + (s.size() / 2) << endl;
}

int main(){
  ios::sync_with_stdio(0);
  string x;
  cin >> x;
  int d = 1;
  while(x[0] != '-'){
    cout << d << ". ";
    solve(x);
    d++;
    cin >> x;
  }
  return 0;
}