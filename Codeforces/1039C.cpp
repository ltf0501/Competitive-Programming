#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
const int kMod = 1e9 + 7;
const int kN = 5e5 + 100;
int n, m, k;
ll a[kN];
int p[kN], sz[kN];
map<ll, vector<pii>> edges;
int kNum;
map<int, int> id;
int p2[kN];
int get_id(int x) {
	if(id.count(x) > 0) return id[x];
	id[x] = ++kNum;
	p[kNum] = kNum, sz[kNum] = 1;
	return kNum;
}
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
bool Union(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return 0;
	if(sz[x] < sz[y]) swap(x, y);
	p[y] = x, sz[x] += sz[y];
	return 1;
}

void add(int &a, int b) {
	a += b;
	if(a >= kMod) a -= kMod;
	if(a < 0) a += kMod;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	p2[0] = 1;
	for(int i = 1; i < kN; i++) p2[i] = 2 * p2[i - 1] % kMod;
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	for(int i = 0, x, y; i < m; i++) {
		scanf("%d%d", &x, &y);
		edges[a[x] ^ a[y]].emplace_back(x, y);
	}
	int ans = p2[n + k];
	for(auto t : edges) {
		vector<pii> v = t.S;
		id.clear(), kNum = 0;
		int cnt = n;
		for(auto p : v) { 
			int x = get_id(p.F), y = get_id(p.S);
			cnt -= Union(x, y);
		}
		add(ans, -p2[n]);
		add(ans, p2[cnt]);
		//printf("%lld: %d\n", t.F, cnt);
	}
	printf("%d\n", ans);
	return 0;
}
