#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000001
 
int pos[MAX];
bool is[MAX];
 
void pre(){
  memset(is, true, sizeof is);
  for (int i = 2; i <= 100; i++) {
    if (is[i]) {
      int x = i * i * i;
      for (int j = x; j <= MAX; j += x) {
        is[j] = false;
      }
    }
  }
  
  int c = 1;
  for (int i = 1; i <= MAX; i++) {
    if (is[i]) {
      pos[i] = c;
      c++;
    }
  }
}
 
int main(){
  #ifdef HOME_TEST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int tc, n;
  scanf("%d", &tc);
  pre();
  for (int tt = 1; tt <= tc; tt++) {
    scanf("%d", &n);
    if (!pos[n]) {
      printf("Case %d: Not Cube Free\n", tt);
      continue;
    }
    printf("Case %d: %d\n", tt, pos[n]);
  }
  return 0;
}