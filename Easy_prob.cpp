#include <bits/stdc++.h>

using namespace std;

void solve(int n){
  if(n <= 3){
    if(n == 3){
      printf("2+2(0)");
    } else if(n == 2){
      printf("2");
    } else if(n == 1){
      printf("2(0)");
    }
    return;
  }
  int x = 1, i;
  for(i = 1; i <= 15; i++){
    x *= 2;
    if(x > n){
      x /= 2;
      i--;
      break;
    }
    if(x == n){
      break;
    }
  }
  printf("2(");
  solve(i);
  printf(")");
  if(n - x){
    printf("+");
  }
  solve(n - x);
}

int main(){
//  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  int tc, n;
  scanf("%d", &tc);
  for(int tt = 0; tt < tc; tt++){
    scanf("%d", &n);
    printf("%d=", n);
    solve(n);
    printf("\n");
  }
  return 0;
} 
