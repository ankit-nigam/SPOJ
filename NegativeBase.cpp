#include <bits/stdc++.h>

using namespace std;

vector <int> a;

void convert(int n) { 
  while (n != 0) {
    int r = n % -2;
    n /= -2;
    if (r < 0) {
      r += 2;
      n++;
    }
    a.push_back(r);
  }
  if (a.size() == 0) {
    a.push_back(0);
  }
  reverse(a.begin(), a.end());
  for (int i = 0; i < (int) a.size(); i++) {
    printf("%d", a[i]);
  }
}

int main(){
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  int n;
  scanf("%d", &n);
  convert(n);
  return 0;
}