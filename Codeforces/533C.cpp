#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;
typedef pair<int, int> pii;
#define F first
#define S second
int pw(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = 1LL * res * a % mod;
		n >>= 1, a = 1LL * a * a % mod;
	}
	return res;
}
vector<pii> edges;
vector<int> g[maxn];
int p[maxn], sz[maxn];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
void Union(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y], p[y] = x;
}
int col[maxn];
bool dfs(int u, int fa, int c) {
	col[u] = c;
	for(int v : g[u]) if(v != fa) {
		if(!col[v]) {
			if(!dfs(v, u, 3 - c)) return 0;
		}
		else if(col[v] == col[u]) return 0;
	}
	return 1;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;
	for(int i = 1; i <= m; i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		x++, y++;
		if(c) Union(x, y);
		else edges.emplace_back(x, y);
	}
	for(auto e : edges) 
		if(find(e.F) == find(e.S)) return puts("0"), 0;
	for(auto e : edges) {
		g[find(e.F)].push_back(find(e.S));
		g[find(e.S)].push_back(find(e.F));
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(find(i) == i && !col[find(i)]) {
		if(!dfs(find(i), -1, 1)) return puts("0"), 0;
		cnt++;
	}
	printf("%d\n", pw(2, cnt - 1));
	return 0;
}
