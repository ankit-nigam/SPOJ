#include <bits/stdc++.h>

using namespace std;

int main(){
   int tc, x, y;
   scanf("%d", &tc);
   for(int t = 0; t < tc; t++){
      scanf("%d %d", &x, &y);
      if(x - y == 2 || x - y == 0){
         if(x % 2 == 0 && y % 2 == 0){
            printf("%d\n", x + y);
         }
         if(x % 2 == 1 && y % 2 == 1){
            printf("%d\n", x + y - 1); 
         }
      } else {
         puts("No Number");
      }
   }
   return 0;
}