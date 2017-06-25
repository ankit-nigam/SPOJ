#include <bits/stdc++.h>

using namespace std;

int main(){
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int a, b, c, d, a1, b1, c1, d1;
  scanf("%d", &a);
  while (a != -1) {
    int res = 0;
    scanf("%d %d %d %d %d %d %d", &b, &c, &d, &a1, &b1, &c1, &d1);
    int w = ceil(a * 1.0 / a1 * 1.0);
    int x = ceil(b * 1.0 / b1 * 1.0);
    int y = ceil(c * 1.0 / c1 * 1.0);
    int z = ceil(d * 1.0 / d1 * 1.0);
    res = max(w, max(x, max(y, z)));
    printf("%d %d %d %d\n", a1 * res - a, b1 * res - b, c1 * res - c, d1 * res - d);
    scanf("%d", &a);
  }
  return 0;
}