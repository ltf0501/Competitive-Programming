#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 3e5 + 10;
int n, m;
ll d[kN];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int x, y, k;
		scanf("%d%d%d", &x, &y, &k);
		d[x] += k, d[y] -= k;
	}
	vector<tuple<int, int, ll>> ans;
	for(int i = 1, j = 1; i <= n; i++) {
		while(d[i] > 0) {
			while(j <= n && d[j] >= 0) j++;
			ll x = min(d[i], -d[j]);
			ans.emplace_back(i, j, x);
			d[i] -= x, d[j] += x;
		}
	}
	printf("%d\n", int(ans.size()));
	for(auto p : ans) printf("%d %d %lld\n", get<0>(p), get<1>(p), get<2>(p));
	return 0;
}
