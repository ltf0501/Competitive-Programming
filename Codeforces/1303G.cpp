#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 1.5e5 + 10;
int n;
vector<int> g[kN];
int a[kN];
struct Line {
	ll m, k;
	Line(ll m = 0, ll k = 0): m(m), k(k) {}
	ll val(int x) {
		return m * x + k;
	}
};
struct Li_Chao {
	vector<Line> tr;
	void init(int _n) {
		tr.clear();
		tr.resize(4 * _n + 10);
	}
	void insert(Line line, int l, int r, int o = 1) {
		if(l == r) {
			if(line.val(l) > tr[o].val(l)) tr[o] = line;
			return;
		}
		int m = (l + r) >> 1;
		if(tr[o].m > line.m) swap(tr[o], line);
		if(tr[o].val(m) < line.val(m)) {
			swap(tr[o], line);
			insert(line, l, m, o << 1);
		}
		else insert(line, m + 1, r, o << 1 | 1);
	}
	ll query(int x, int l, int r, int o = 1) {
		if(l == r) return tr[o].val(x);
		int m = (l + r) >> 1;
		if(x <= m) return max(tr[o].val(x), query(x, l, m, o << 1));
		else return max(tr[o].val(x), query(x, m + 1, r, o << 1 | 1));
	}
};
vector<int> now;
bool vis[kN];
int sz[kN], mx[kN];
int dep[kN];
ll pre[kN], suf[kN], sum[kN];
ll ans;
void get_cen(int u) {
	now.push_back(u);
	vis[u] = 1, sz[u] = 1, mx[u] = 0;
	for(int v : g[u]) if(!vis[v]) {
		get_cen(v);
		sz[u] += sz[v], mx[u] = max(mx[u], sz[v]);
	}
}
void get_dis(int cen, int u, int d, ll _sum, ll _pre, ll _suf, vector<int> &tmp) {
	now.push_back(u);
	tmp.push_back(u);
	vis[u] = 1;
	sum[u] = _sum, pre[u] = _pre, suf[u] = _suf, dep[u] = d;
	for(int v : g[u]) if(!vis[v]) {
		get_dis(cen, v, d + 1, _sum + a[v], _pre + 1LL * (d + 2) * a[v], _suf + _sum - a[cen] + a[v], tmp);
	}
}
void dfs(int u) {
	get_cen(u);	
	int cen = -1;
	int size = int(now.size());
	for(int w : now) {
		if(max(mx[w], size - sz[w]) * 2 <= size) cen = w; 
		vis[w] = 0;
	}
	now.clear();

	vector<vector<int>> son;
	son.push_back({cen});
	pre[cen] = sum[cen] = a[cen], suf[cen] = 0, dep[cen] = 0;
	vis[cen] = 1;
	for(int v : g[cen]) if(!vis[v]) {
		vector<int> tmp;
		get_dis(cen, v, 1, a[cen] + a[v], 2LL * a[v] + a[cen], a[v], tmp);
		son.push_back(tmp);
	}
	for(int w : now) vis[w] = 0;
	now.clear();
	//printf("cen = %d\n", cen);
	//for(int w : now) {
	//	printf("%d: dep = %d, sum = %lld, pre = %lld, suf = %lld\n", w, dep[w], sum[w], pre[w], suf[w]);
	//}

	Li_Chao tree;
	tree.init(size);
	//printf("%d init\n", cen);
	for(int i = 0; i < int(son.size()); i++) {
		auto tmp = son[i];
		if(i) {
			for(int x : tmp) {
				ll que = tree.query(dep[x], 0, size) + suf[x];
				ans = max(ans, que); 
				//printf("query: d = %d, suf = %lld, ans = %lld\n", dep[x], suf[x], que);
			}
		}
		for(int x : tmp) {
			tree.insert(Line(sum[x], pre[x]), 0, size);
			//printf("insert: m = %lld, k = %lld\n", sum[x], pre[x]); 
		}
	}
	
	tree.init(size);
	reverse(son.begin(), son.end());
	//printf("%d init\n", u);
	for(int i = 0; i < int(son.size()); i++) {
		auto tmp = son[i];
		if(i) {
			for(int x : tmp) {
				ll que = tree.query(dep[x], 0, size) + suf[x];
				ans = max(ans, que); 
				//printf("query: d = %d, suf = %lld, ans = %lld\n", dep[x], suf[x], que);
			}
		}
		for(int x : tmp) {
			tree.insert(Line(sum[x], pre[x]), 0, size);
			//printf("insert: m = %lld, k = %lld\n", sum[x], pre[x]); 
		}
	}
	for(int v : g[cen])
		if(!vis[v]) dfs(v);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}
