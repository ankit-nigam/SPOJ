#include <bits/stdc++.h>

using namespace std;

int a[2010];

int fin(int x, int low, int high){
  int res = -1;
  int mid = 0;
  while(low <= high){
    mid = (low + high) / 2;
    if(a[mid] > x){
      res = mid;
      high = mid - 1;
    } else if(a[mid] <= x){
      low = mid + 1;
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  while(n){
    for(int i = 0; i < n; i++){
      cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n - 2; i++){
      for(int j = i + 1; j < n - 1; j++){
        int res = fin(a[i] + a[j], j + 1, n - 1);
        if(res > 0){
          ans += (n - res);
        }
      }
    }
    cout << ans << endl;
    cin >> n;
  }
  return 0;
}