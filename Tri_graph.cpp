#include <bits/stdc++.h>

using namespace std;

int main(){
  #ifdef HOME_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int n;
  scanf("%d", &n);
  int tc = 1;
  while (n != 0) {
    int a[n + 1][4];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 3; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (i == 1) {
        a[i][3] += a[i][2];
      } else if (i == 2) {
        a[i][1] += a[i - 1][2];
        a[i][2] += min(a[i][1], min(a[i - 1][2], a[i - 1][3]));
        a[i][3] += min(a[i][2], min(a[i - 1][2], a[i - 1][3]));
      } else {
        a[i][1] += min(a[i - 1][1], a[i - 1][2]);
        a[i][2] += min(a[i - 1][1], min(a[i - 1][2], min(a[i - 1][3], a[i][1])));
        a[i][3] += min(a[i][2], min(a[i - 1][2], a[i - 1][3]));
      }
    }
    printf("%d. %d\n", tc, a[n][2]);
    tc++;
    scanf("%d", &n);
  }
  return 0;
}     