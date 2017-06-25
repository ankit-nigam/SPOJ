#include <bits/stdc++.h>

using namespace std;

int mul(int a, int b){
  return (long long) a * b;
}

int power(int a, int b){
  int res = 1;
  while(b > 0){
    if(b & 1){
      res = mul(a, res);
    }
    b >>= 1;
    a = mul(a, a);
  }
  return res;
}

int main(){
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  int n;
  scanf("%d", &n);
  while(n){  
    if(n == 1){
      printf("1\n");
      scanf("%d", &n);
      continue;
    }
    if(n == 2 || n == 3){
      printf("2\n");
      scanf("%d", &n);
      continue;
    }
    int a = floor(log2(n));
    a = (n - power(2, a));
    if(a == 0){
      printf("%d\n", power(2, (int) log2(n)));
    } else {
      printf("%d\n", 2 * a);
    }
    scanf("%d", &n);
  }
  return 0;
}