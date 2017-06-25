#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

//MODiFIED MERGE SORT APPROACH
 
ll _merge(int a[], int tmp[], int l, int mid, int r) {
  int i, j, k;
  ll inv = 0; //i for left subarray, j for rightsubarray
  i = k = l; 
  j = mid;
  while ((i < mid) && (j <= r)) {
    if (a[i] <= a[j]) {
      tmp[k++] = a[i++];
    } else {
      tmp[k++] = a[j++];
      inv += (ll) (mid - i);
    }
  }
  while (i < mid) {
    tmp[k++] = a[i++];
  }
  while (j <= r) {
    tmp[k++] = a[j++];
  }
  for (i = l; i <= r; i++) {
    a[i] = tmp[i];
  }
  return inv;
}
 
ll mergeSort(int a[], int tmp[], int l, int r) {
  int mid;
  ll inv = 0;
  if (l < r) {
    mid = (l + r) >> 1;
    inv = mergeSort(a, tmp, l, mid);
    inv += mergeSort(a, tmp, mid + 1, r);
    inv += _merge(a, tmp, l, mid + 1, r);
  }
  return inv;
}
 
int main() {
  #ifdef HOME
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
  #endif
  
  int tc, n;
  cin >> tc;
  for (int tt = 0; tt < tc; tt++) {
    cin >> n;
    int a[n + 1], tmp[n + 1];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    cout << mergeSort(a, tmp, 0, n - 1) << endl;
  }
   
  #ifdef HOME
    fprintf(stderr, "Time taken:- %.3fs\n", (double) clock() / CLOCKS_PER_SEC);
    fflush(stderr);
  #endif
  return 0;
} 
