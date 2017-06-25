#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
  ios::sync_with_stdio(0);
  int tc, n;
  scanf("%d", &tc);
  for(int t = 0; t < tc; t++){
    bool ok = false;
    scanf("%d", &n);
    int d[2010] = {0};
    int a[n];
    for(int i = 0; i < n; i++){
      scanf("%d", &a[i]);
      if(a[i] < 0){
         d[1000 + abs(a[i])]++;
      } else{
         d[a[i]]++;
      }
    }
    for(int i = 0; i <= 2 * 1000; i++){
      if(d[i] > (n / 2)){
        if(i > 1000){
          printf("YES %d\n", 1000 - i);
          ok = true;
          break;
        } else{
          printf("YES %d\n", i);
          ok = true;
          break;
        }
      }
    }
    if(!ok){
      puts("NO");
    }
  }
  return 0;
} 