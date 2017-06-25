#include <bits/stdc++.h>

using namespace std;

int main(){
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int n;
  scanf("%d", &n);
  while (n) {
    int ans = n * 5;
    n--;
    int x = 2 + (n - 1) * 3;
    ans += n * (2 + x) / 2;
    printf("%d\n", ans);
    scanf("%d", &n);
  }
  return 0;
}