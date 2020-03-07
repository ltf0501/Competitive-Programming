#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int kMod = 1e9 + 7;
#define F first
#define S second
const int kN = 1e5 + 10;
vector<int> g[kN];
int n;
int a[kN], inva[kN];
int sz[kN], mx[kN];
int dis[20][kN];
bool vis[kN];
vector<pii> pos[kN];
vector<int> now;

int pw(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = 1LL * res * a % kMod;
		n >>= 1, a = 1LL * a * a % kMod;
	}
	return res;
}
int INV(int a) {return pw(a, kMod - 2);}

struct P {
	int fa, dep, sum, sub, w;
	P(){}
	P(int fa, int dep, int sum, int sub, int w):
		fa(fa), dep(dep), sum(sum), sub(sub), w(w) {}
} cent[kN];

void get_cen(int u) {
	vis[u] = 1;
	now.push_back(u);
	sz[u] = 1, mx[u] = 0;
	for(int v : g[u]) if(!vis[v]) {
		get_cen(v);
		sz[u] += sz[v];
		mx[u] = max(mx[u], sz[v]);
	} 
}
void get_dis(int u, int d, int dep) {
	vis[u] = 1;
	now.push_back(u);
	dis[dep][u] = d;
	for(int v : g[u]) if(!vis[v]) {
		get_dis(v, d + 1, dep);
	}
}
int dfs(int u, int dep) {
	get_cen(u);	
	int cen = -1;
	for(int w : now) {
		if(max(mx[w], sz[u] - sz[w]) <= sz[u] / 2) cen = w;
	}
	cent[cen].dep = dep;
	for(int w : now) vis[w] = 0;
	now.clear();

	get_dis(cen, 0, dep);
	for(int w : now) vis[w] = 0;
	now.clear();

	vis[cen] = 1;
	for(int v : g[cen]) if(!vis[v]) {
		int son = dfs(v, dep + 1);
		cent[son].fa = cen;
	}
	return cen;
}
void add(int &a, int b, int type) {
	a += b * type;
	if(a >= kMod) a -= kMod;
	if(a < 0) a += kMod;
}
int update(int u, int type) {
	int res = 0;
	int dep = cent[u].dep;
	add(res, 1LL * inva[u] * cent[u].sum % kMod, type);
	int now = u;
	while(dep--) {
		int fa = cent[now].fa;
		int d = dis[dep][u];
		int sum = 1LL * inva[u] * (1LL * d * cent[fa].w % kMod + 1LL * cent[fa].sum % kMod) % kMod;
		add(res, sum, type);
		sum = 1LL * inva[u] * (1LL * d * cent[now].w % kMod + 1LL * cent[now].sub % kMod) % kMod;
		add(res, sum, -type);

		add(cent[fa].sum, 1LL * inva[u] * d % kMod, type); 
		add(cent[now].sub, 1LL * inva[u] * d % kMod, type);
		now = fa;
	}
	now = u;
	while(now) {
		add(cent[now].w, inva[u], type);
		now = cent[now].fa;
	}
	//printf("u = %d, type = %d, res = %d\n", u, type, res);
	return res;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		r++;
		a[i] = r - l;
		inva[i] = INV(a[i]);
		pos[l].push_back({i, 1});
		pos[r].push_back({i, -1});
	}

	int tot = 1;
	for(int i = 1; i <= n; i++) tot = 1LL * tot * a[i] % kMod;

	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	int rt = dfs(1, 0);
	//printf("rt = %d\n", rt);
	//for(int i = 1; i <= n; i++) {
	//	printf("cen_fa[%d] = %d\n", i, cent[i].fa);
	//}

	int ans = 0, cur = 0;
	for(int i = 1; i < kN; i++) {
		int tmp = 0;
		for(auto s : pos[i]) {
			add(tmp, update(s.F, s.S), 1);
		}
		add(cur, tmp, 1);
		add(ans, cur, 1);
	}
	printf("%lld\n", 1LL * ans * tot % kMod);
	return 0;
}
