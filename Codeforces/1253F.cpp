#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long ll;
const ll INF = 1e16;
typedef pair<ll, int> pli;
#define F first
#define S second
struct E {
	int x, y;
	ll d;
	bool operator < (const E& r) const {return d < r.d;}
};
vector<E> edges;
int to(int x, int id) {return x ^ edges[id].x ^ edges[id].y;}
vector<int> g[maxn];
vector<pli> g2[maxn];
int n, m, k, q;
ll dis[maxn];
bool vis[maxn];
int p[maxn], sz[maxn];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
bool Union(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return 0;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y], p[y] = x;
	return 1;
}

int in[maxn], out[maxn], dfs_clock;
int anc[20][maxn];
ll ancmax[20][maxn];
void dfs(int u, int fa) {
	in[u] = ++dfs_clock;
	for(pli v : g2[u]) if(v.S != fa) {
		anc[0][v.S] = u, ancmax[0][v.S] = v.F;
		dfs(v.S, u); 
	}
	out[u] = dfs_clock;
}
bool ancestor(int x, int y) {return in[x] <= in[y] && out[x] >= out[y];}
ll query(int x, int y) {
	if(ancestor(y, x)) swap(x, y);
	ll res = 0;
	for(int i = 19; i >= 0; i--) if(!ancestor(anc[i][y], x)) 
		res = max(res, ancmax[i][y]), y = anc[i][y];
	res = max(res, ancmax[0][y]), y = anc[0][y];
	if(x == y) return res;

	for(int i = 19; i >= 0; i--) if(!ancestor(anc[i][x], y)) 
		res = max(res, ancmax[i][x]), x = anc[i][x];
	res = max(res, ancmax[0][x]), x = anc[0][x];
	return res;
}
int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for(int i = 0; i < m; i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		g[x].push_back(i), g[y].push_back(i);
		edges.push_back({x, y, c});
	}
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	for(int i = 1; i <= k; i++) pq.push({0, i});
	for(int i = k + 1; i <= n; i++) dis[i] = INF;
	while(!pq.empty()) {
		pli t = pq.top(); pq.pop();
		if(vis[t.S]) continue;
		vis[t.S] = 1;
		for(int id : g[t.S]) {
			int v = to(t.S, id);
			if(t.F + edges[id].d < dis[v]) {
				dis[v] = t.F + edges[id].d;
				pq.push({dis[v], v});
			}
		}
	}
	
//	for(int i = 1; i <= n; i++) 
//		printf("dis[%d] = %lld\n", i, dis[i]);
	for(E& e : edges) e.d += dis[e.x] + dis[e.y];

	sort(edges.begin(), edges.end());
	for(int i = 1; i <= n; i++) p[i] = i, sz[i] = 1;

	for(E e : edges) {
		if(Union(e.x, e.y)) {
			g2[e.x].push_back({e.d, e.y});
			g2[e.y].push_back({e.d, e.x});
		}
	}
	dfs(1, 0); out[0] = dfs_clock;
	for(int j = 1; j <= 19; j++) {
		for(int i = 1; i <= n; i++) {
			anc[j][i] = anc[j - 1][anc[j - 1][i]];
			ancmax[j][i] = max(ancmax[j - 1][i], ancmax[j - 1][anc[j - 1][i]]);
		}
	}
//	for(int i = 1; i <= n; i++) {
//		printf("%d: ", i);
//		for(int j = 0; j < 4; j++) printf("%lld ", ancmax[j][i]); puts("");
//	}
	while(q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", query(x, y));
	}
	return 0; 
}
