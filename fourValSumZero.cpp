#include <bits/stdc++.h>

using namespace std;

int a[4010][4010];
int s[17000010];

int fin(int c[], int low, int high, int x, bool findl) {
  int res = -1;
  while (low <= high) {
    int mid = (low + high)>>1;
    if (c[mid] == x) {  
      res = mid;
      if (findl) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else if (c[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return res;
}

int main(){
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int n, ans = 0;
  scanf("%d", &n);
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < 4; i++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < 4; i++) {
    sort(a[i], a[i] + n);
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      s[c] = a[2][i] + a[3][j];
      c++;
    }
  }
  sort(s, s + c);
  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < n; j++) { 
      int x = a[0][i] + a[1][j];
      int y = fin(s, 0, c - 1, -x, true);
      if (y != -1) {
        ans += (fin(s, 0, c - 1, -x, false) - y + 1);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}