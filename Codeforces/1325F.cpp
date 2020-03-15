#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10;
const int kM = 2e5 + 10;
typedef pair<int, int> pii;
#define F first
#define S second
int n, m;
vector<int> g[kN];
vector<pii> edges;
int to(int u, int id) {return u ^ edges[id].F ^ edges[id].S;}
bool back[kM];
int in[kN], out[kN], dfs_clock;
int anc[20][kN], dep[kN];
void dfs(int u, int fa = 0, int d = 0) {
	in[u] = ++dfs_clock;
	anc[0][u] = fa;
	dep[u] = d;
	for(int i : g[u]) {
		int v = to(u, i);
		if(v == fa) continue;
		if(!in[v]) dfs(v, u, d + 1);
		else back[i] = 1;
	}
	out[u] = dfs_clock;
}
bool ancestor(int x, int y) {return in[x] <= in[y] && out[x] >= out[y];}
int LCA(int x, int y) {
	if(ancestor(x, y)) return x;
	if(ancestor(y, x)) return y;
	for(int i = 17; i >= 0; i--)
		if(!ancestor(anc[i][x], y)) x = anc[i][x];
	return anc[0][x];
}
int Dis(int x, int y) {return dep[x] + dep[y] - 2 * dep[LCA(x, y)];}

vector<int> Climb(int u, int v) {
	if(ancestor(u, v)) swap(u, v);
	vector<int> res;
	do {
		res.push_back(u);
		u = anc[0][u];
	}while(!ancestor(u, v));

	res.push_back(u);
	if(u == v) return res;

	swap(u, v);
	vector<int> tmp;
	do {
		tmp.push_back(u);
		u = anc[0][u];
	}while(!ancestor(u, v));
	reverse(tmp.begin(), tmp.end());
	for(int x : tmp) res.push_back(x);
	return res;
}

bool mark[kN];
void dfs2(int u, int fa = 0) {
	for(int i : g[u]) {
		int v = to(u, i);
		if(v != fa && !back[i]) dfs2(v, u);
	}
	if(!mark[u]) {
		for(int i : g[u]) {
			mark[to(u, i)] = 1;
		}
	} 
}
int main() {
	scanf("%d%d", &n, &m);
	int sq = 0;
	while(sq * sq < n) sq++;
	for(int i = 0, x, y; i < m; i++) {
		scanf("%d%d", &x, &y);
		int sz = edges.size();
		g[x].push_back(sz), g[y].push_back(sz);
		edges.emplace_back(x, y);
	}
	dfs(1); out[0] = dfs_clock;
	for(int j = 1; j <= 17; j++)
		for(int i = 1; i <= n; i++) anc[j][i] = anc[j - 1][anc[j - 1][i]];

	for(int i = 0; i < m; i++) if(back[i]) {
		int u = edges[i].F, v = edges[i].S;
		//printf("u = %d, v = %d, Dis = %d\n", u, v, Dis(u, v));
		if(Dis(u, v) + 1 >= sq) {
			puts("2");
			vector<int> ans = Climb(u, v);
			printf("%d\n", int(ans.size()));
			for(int x : ans) printf("%d ", x); puts("");
			return 0;
		}
	}

	dfs2(1);
	puts("1");
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(!mark[i]) {
			printf("%d ", i);
			if(++cnt == sq) break;
		}
	}
	puts("");
	return 0;
}
