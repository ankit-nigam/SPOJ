#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

//MODiFIED MERGE SORT APPROACH

/*
Let a be our original array a[];
let l be left sorted sub-array of a[], l[] = [1, 2, 6, 7];
ans r be right sorted sub-array of a[], r[] = [3, 4, 5, 8];
now mid = (l + r) / 2; mid = (0 + 7) / 2 == 3;
now let i represent index of l[], j for r[];
for i == 0 && j == mid + 1, no inversion (1 < 3), increament i;
for i == 1 && j == mid + 1, no inversion (2 < 3), i++;
for i == 2 && j = mid + 1, inv = (mid + 1 - i), i.e inv = 4 - 2 = 2, we have to do two inversion that is (6, 3) and (7, 3), j++;
for i == 2 && j = mid + 2, again (6 > 4 && 7 > 4) so inv += (mid + 1 - i), inv += (4 - 2) = 4, j++;
same process of (6, 5) & (7, 3);
in this manner we have to count inversions

time comlexity == O(nlogn);
*/
 
ll _merge(int a[], int tmp[], int l, int mid, int r) {
  int i, j, k;
  ll inv = 0; //i for left subarray, j for right subarray
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
    inv = mergeSort(a, tmp, l, mid);  //add inversion counts from the left subarray
    inv += mergeSort(a, tmp, mid + 1, r); //add inversion counts from right subarray
    inv += _merge(a, tmp, l, mid + 1, r); //add inversion counts during the _merge process;
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
