#include <bits/stdc++.h>

using namespace std;

#define max 10000001
 
bool done[max];
int a[1000001];

void pre(){
  memset(done, false, sizeof done);
  done[0] = true;
  a[0] = 0;
  for(int i = 1; i <= 500000; i++){
    int x = a[i - 1] - i;
    if(x > 0 && !done[x]){
      a[i] = a[i - 1] - i;
    } else{
      a[i] = a[i - 1] + i;
    }
    done[a[i]] = true;
  }
}

int main(){
  ios::sync_with_stdio(0);
  pre();
  int n;
  cin >> n;
  while(n != -1){
    cout << a[n] << endl;
    cin >> n;
  }      
  return 0;
}