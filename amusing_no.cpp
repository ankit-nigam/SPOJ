#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
   ios::sync_with_stdio(0);
   int tc;
   scanf("%d", &tc);
   ll k;
   for(int t = 0; t < tc; t++){
      scanf("%lld", &k);
      k++;
      vector <int> a;
      while(k > 1){
         a.push_back(k % 2);
         k /= 2;
      }
      for(int i = a.size() - 1; i >= 0; i--){
         if(a[i] == 0){
            printf("5");
         } else{
            printf("6");
         }
      }
      printf("\n");
   }
   return 0;
}