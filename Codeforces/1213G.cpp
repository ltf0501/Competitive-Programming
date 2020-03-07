#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
const int maxn = 2e5 + 10;
ll ans[maxn], cur;
ll c[maxn];
int n;
vector<pii> v[maxn];
int p[maxn], sz[maxn];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
void Union(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	if(sz[x] <= sz[y]) swap(x, y);
	cur += (c[sz[x] + sz[y]] - c[sz[x]] - c[sz[y]]);
	p[y] = x, sz[x] += sz[y];
}
int main() {
	for(int i = 1; i < maxn; i++) c[i] = 1LL * i * (i - 1) / 2; 
	int q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i < n; i++) {
		int x, y, d;
		scanf("%d%d%d", &x, &y, &d);
		v[d].push_back(make_pair(x, y));
	}
	for(int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
	for(int i = 1; i < maxn; i++) {
		for(auto p : v[i]) Union(p.F, p.S);
		ans[i] = cur;
	}
	while(q--) {
		int x;
		scanf("%d", &x);
		printf("%lld\n", ans[x]);
	}
	return 0;
}
