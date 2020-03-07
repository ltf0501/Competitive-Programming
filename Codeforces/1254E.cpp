#include <bits/stdc++.h>
using namespace std;
const int kN = 5e5 + 10;
const int kMod = 1e9 + 7;
typedef pair<int, int> pii;
#define F first
#define S second

void bye() {
	puts("0");
	exit(0);
}

int n;
int a[kN];
vector<int> g[kN];
int nxt[kN], pre[kN];
bool vis[kN];
vector<pii> cond[kN];
int dep[kN];
int p[kN]; 
void dfs(int u, int fa = 0, int d = 0) {
	dep[u] = d, p[u] = fa;
	for(int v : g[u])
		if(v != fa) dfs(v, u, d + 1);
}
int tot;
void gao(int u, int v) {
	if(u == v) bye();
	vector<int> res1, res2; 	
	res1.push_back(n + 1);
	res2.push_back(n + 2);
	while(dep[u] > dep[v]) res1.push_back(u), u = p[u];
	while(dep[v] > dep[u]) res2.push_back(v), v = p[v];
	while(u != v) {
		res1.push_back(u), u = p[u];
		res2.push_back(v), v = p[v];
	}
	res1.push_back(u);
	reverse(res2.begin(), res2.end());
	for(int x : res2) res1.push_back(x);
	tot += int(res1.size()) - 3;
	if(tot > 2 * n - 2) bye();
	for(int i = 1; i < int(res1.size()) - 1; i++)
		cond[res1[i]].emplace_back(res1[i - 1], res1[i + 1]);
}
int main() {
	scanf("%d", &n);
	for(int i = 1, x, y, m; i < n; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	if(n == 1) return puts("1"), 0;
	
	for(int i = 1; i <= n; i++) g[i].push_back(n + 1), g[i].push_back(n + 2);
	dfs(1);

	for(int i = 1; i <= n; i++)
		if(a[i]) gao(a[i], i);

	int ans = 1;
	for(int i = 1; i <= n; i++) {
		for(int v : g[i]) vis[v] = pre[v] = nxt[v] = 0;
		for(auto e : cond[i]) {
			if(nxt[e.F] && nxt[e.F] != e.S) bye();
			if(pre[e.S] && pre[e.S] != e.F) bye();
			nxt[e.F] = e.S, pre[e.S] = e.F; 
		}

		for(int v : g[i]) if(!vis[v]) {
			vis[v] = 1;
			int cur = nxt[v];
			while(cur) {
				if(cur == v) bye();
				if(vis[cur]) break;
				vis[cur] = 1;
				cur = nxt[cur];
			}
		}

		if(nxt[n + 1]) {
			int cur = n + 1, sz = 1;
			while(cur) {
				if(cur == n + 2) break;
				sz++;
				cur = nxt[cur];
			}
			if(cur == n + 2 && sz < int(g[i].size())) bye();
		}
		int chain = 0;
		for(int v : g[i]) 
			if(v <= n && !pre[v]) chain++;
		if(pre[n + 2]) chain--;
		for(int j = 1; j <= chain; j++) ans = 1LL * ans * j % kMod;
	}
	printf("%d\n", ans);
	return 0;
}

