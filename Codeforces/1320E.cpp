#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
typedef pair<int, int> pii;
#define F first
#define S second
 
int n;
vector<int> g[kN];
vector<pii> g_vir[kN];
pii ans[kN];
int spe[kN];
 
int in[kN], out[kN], dfs_clock;
int dep[kN], anc[20][kN];
 
void dfs(int u, int fa = 0, int d = 0) {
	in[u] = ++dfs_clock, dep[u] = d, anc[0][u] = fa;
	for(int v : g[u])
		if(v != fa) dfs(v, u, d + 1);
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
 
void BuildVirtualTree(vector<int> &v) {
	vector<int> tmp;
	for(int i = 0; i < int(v.size()) - 1; i++) tmp.push_back(LCA(v[i], v[i + 1]));
	for(int x : tmp) v.push_back(x);
	sort(v.begin(), v.end(), [&](int i, int j) {return in[i] < in[j];});
	v.resize(unique(v.begin(), v.end()) - v.begin());
 
	stack<int> s;
	for(int x : v) {
		while(!s.empty() && !ancestor(s.top(), x)) s.pop();
		if(!s.empty()) g_vir[s.top()].emplace_back(x, Dis(s.top(), x));
		s.push(x);
	}
 
	//for(int x : v) {
	//	printf("%d: ", x);
	//	for(auto y : g_vir[x]) printf("(%d, %d) ", y.F, y.S); puts("");
	//}
}
 
pii CalStep(int idx, int dis, const vector<pii> &virus) {
	if(virus[idx].S == 0) {
		//printf("not a virus: idx = %d\n", idx);
		assert(0);
	}
	return {(dis + virus[idx].S - 1) / virus[idx].S, idx};
}
 
pii dfs2(int u, const vector<pii> &virus) { // return (spe, dis)
	pii res = ans[u] = {-1, -1};
	for(auto v : g_vir[u]) {
		pii tmp = dfs2(v.F, virus);
		tmp.S += v.S;
		if(tmp.F == -1) continue;
		if(res.F == -1 || CalStep(tmp.F, tmp.S, virus) < CalStep(res.F, res.S, virus))
			res = tmp;
	}
	if(spe[u] != -1) res = {spe[u], 0};
	//printf("ans[%d] = (%d, %d)\n", u, res.F, res.S);
	return ans[u] = res;
}
 
void dfs3(int u, int d, const vector<pii> &virus, int fa = 0) {
	if(fa) {
		pii tmp = ans[fa];
		if(tmp.F != -1) {
			tmp.S += d;
			if(ans[u].F == -1 || CalStep(tmp.F, tmp.S, virus) < CalStep(ans[u].F, ans[u].S, virus))
				ans[u] = tmp;
		}
	}
	for(auto v : g_vir[u]) dfs3(v.F, v.S, virus, u);
}
 
int main() {
	scanf("%d", &n);
	for(int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
 
	dfs(1); out[0] = dfs_clock;
	for(int j = 1; j <= 17; j++)
		for(int i = 1; i <= n; i++) anc[j][i] = anc[j - 1][anc[j - 1][i]];
 
	memset(spe, -1, sizeof(spe));
	//for(int i = 1; i <= n; i++) ans[i] = {-1, -1};
	int q; scanf("%d", &q);
	while(q--) {
		int k, m; scanf("%d%d", &k, &m);
 
		vector<pii> virus(k);
		vector<int> target(m), tmp;
		for(int i = 0; i < k; i++) {
			scanf("%d%d", &virus[i].F, &virus[i].S);
			tmp.push_back(virus[i].F);
			spe[virus[i].F] = i;
		}
		for(int i = 0; i < m; i++) {
			scanf("%d", &target[i]);
			tmp.push_back(target[i]);
		}
		sort(tmp.begin(), tmp.end(), [&](int i, int j) {return in[i] < in[j];});
		tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
 
		BuildVirtualTree(tmp);
		//for(int x : tmp) printf("%d ", x); puts("");
 
		dfs2(tmp[0], virus);
		dfs3(tmp[0], 0, virus);
		for(int x : target) printf("%d ", ans[x].F + 1); puts("");
 
		for(int x : tmp) {
			g_vir[x].clear();
			spe[x] = -1;
		}
	}
	return 0;
}
