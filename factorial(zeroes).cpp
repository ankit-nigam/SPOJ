#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  int tc, n;
  scanf("%d", &tc);
  for(int t = 0; t < tc; t++){
    int ans = 0;
    scanf("%d", &n);
    while(n >= 5){
      ans += (n / 5);
      n /= 5;
    }
    printf("%d\n", ans);
  }
  return 0;
}