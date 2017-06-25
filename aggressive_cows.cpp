#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
 
int n, c;
int a[100010];
 
int f(int x){
   ll cp = 1, lastp = a[0];
   for(int i = 1; i < n; i++){
      if(a[i] - lastp >= x){
        cp++;
        if(cp == c){
           return 1;
        }
        lastp = a[i];
      }
   }
   return 0;
}
 
int binarysearch(){
   int start = 0, end = a[n - 1];
   while(start < end){
      int mid = (start + end) / 2;
      if(f(mid)){
         start = mid + 1;
      } else{
         end = mid;
      }
   }
   return start - 1;
}
 
int main(){
   ios::sync_with_stdio(0);
   int t;
   cin >> t;
   for(int i = 0; i < t; i++){
      scanf("%d %d", &n, &c);
      for(int m = 0; m < n; m++){
         scanf("%d", &a[m]);
      }
      sort(a, a + n);
      printf("%d\n", binarysearch());
   }
   return 0;
} 