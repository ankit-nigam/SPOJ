#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 500
 
typedef long long ll;
 
int mul(int x, int res[], int res_size){
  int tem = 0;
  for(int i = 0; i < res_size; i++){
    int prod = res[i] * x + tem;
    res[i] = prod % 10;
    tem = prod / 10;
  }
  while(tem){
    res[res_size] = tem % 10;
    tem = tem / 10;
    res_size++;
  }
  return res_size;
}
 
void fact(int n){
  int res[MAX];
  res[0] = 1;
  int res_size = 1;
  for(int i = 2; i <= n; i++){
    res_size = mul(i, res, res_size);
  }
  for(int i = res_size - 1; i >= 0; i--) cout << res[i];
  cout << endl;
}
 
int main(){
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int n;
    cin >> n;
    fact(n);
  }
  return 0;
} 