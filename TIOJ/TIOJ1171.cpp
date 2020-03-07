#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define maxp 18
#define ll long long
struct node {
	int to, dis;
};
struct Cen {
	int p, sz, dep;
	ll val, no;
} cen[maxn];
vector<node> g[maxn];
vector<int> now;
int sz[maxn], mx[maxn];
ll dis[maxp][maxn];
bool vis[maxn];
void get_cen(int u) {
	vis[u] = 1;
	sz[u] = 1;
	mx[u] = 0;
	now.push_back(u);
	for (node v : g[u])
		if (!vis[v.to]) {
			get_cen(v.to);
			sz[u] += sz[v.to];
			mx[u] = max(mx[u], sz[v.to]);
		}
}
void get_dis(int u, int dep, ll w) {
	dis[dep][u] = w;
	vis[u] = 1;
	for (node v : g[u])
		if (!vis[v.to]) get_dis(v.to, dep, w + v.dis);
}
void dfs(int u, int dep, int p) {
	get_cen(u);
	int s = now.size();
	int tmp = -1;
	for (int w : now) {
		if (max(s - sz[w], mx[w]) <= s / 2) tmp = w;
		vis[w] = 0;
	}
	get_dis(tmp, dep, 0);
	for (int w : now) vis[w] = 0;
	now.clear();
	vis[tmp] = 1;
	cen[tmp] = (Cen){p, 0, dep, 0, 0};
	// printf("%d %d\n",u,tmp);
	for (node v : g[tmp])
		if (!vis[v.to]) dfs(v.to, dep + 1, tmp);
}
void add(int u) {
	int p = u;
	while (p != -1) {
		cen[p].val += dis[cen[p].dep][u];
		cen[p].no += dis[cen[p].dep - 1][u];
		cen[p].sz++;
		p = cen[p].p;
	}
}
ll query(int u) {
	int p = u;
	ll ret = 0;
	int Sz = 0;
	while (p != -1) {
		ret += cen[p].val - cen[p].no;
		ret += (cen[p].sz - Sz) * dis[cen[p].dep][u];
		Sz = cen[p].sz;
		p = cen[p].p;
	}
	return ret;
}
main() {
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n - 1; i++) {
		int x, y, d;
		scanf("%d%d%d", &x, &y, &d);
		g[x].push_back((node){y, d}), g[y].push_back((node){x, d});
	}
	dfs(0, 1, -1);
	memset(vis, 0, sizeof(vis));
	// for(int i=1;i<=n;i++)printf("%d %d\n",cen[i].p,cen[i].dep);
	while (q--) {
		int c, x;
		scanf("%d%d", &c, &x);
		if (c == 1 && !vis[x])
			add(x), vis[x] = 1;
		else if (c == 2)
			printf("%lld\n", query(x));
	}
	return 0;
}
/*
   13 10
   1 2 1
   2 3 1
   3 4 1
   3 5 1
   2 6 1
   1 7 1
   7 8 1
   7 9 1
   1 10 1
   10 11 1
   11 12 1
   11 13 1
   */
