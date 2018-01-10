#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

void build(int node, int l, int r) {
	if (l == r) {
		sum[node] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * node, l, mid);
	build(2 * node + 1, mid + 1, r);
	sum[node] = sum[2 * node] + sum[2 * node + 1];
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	return 0;
}