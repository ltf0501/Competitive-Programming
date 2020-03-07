#if !defined(YCM) && 1
#define _FORTIFY_SOURCE 0
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx")
#endif
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
const int maxd = 50;
int n, m, d;
char pos[maxn][maxd + 5];
int id(int u, int t) {
	return u + t * n;
}
int time(int id) {
	return id / n;
}
int node(int id) {
	return id % n;
}

vector<int> g[maxn];
int sccno[maxn * maxd], scc_cnt;
int in[maxn * maxd], dfs_clock;
int num[maxn * maxd];
vector<int> scc[maxn * maxd];
vector<int> s;
int dfs(int u) {
	s.push_back(u);
	int lowu = in[u] = ++dfs_clock;
	int t = time(u);
	for(int v : g[node(u)]) {
		v = id(v, (t + 1) % d);
		if(!in[v]) lowu = min(lowu, dfs(v));
		else if(!sccno[v]) lowu = min(lowu, in[v]);
	}
	if(lowu == in[u]) {
		scc_cnt++;
		while(1) {
			int x = s.back(); s.pop_back();
			sccno[x] = scc_cnt;
			scc[scc_cnt].push_back(x);
			if(x == u) break;
		}
	}
	return lowu;
}
vector<int> scc_g[maxn * maxd];
int dp[maxn * maxd];
bool vis[maxn * maxd];
vector<int> tmp;
void cal_scc() {
	for(int i = 0; i < n * d; i++)
		if(!in[i]) dfs(i);
	
	for(int i = 1; i <= scc_cnt; i++) {
		tmp.clear();
		for(int x : scc[i])
			if(!vis[node(x)] && pos[node(x)][time(x)] == '1') num[i]++, vis[node(x)] = 1, tmp.push_back(x);
		for(int x : tmp) vis[node(x)] = 0;
	}

//	for(int i = 1; i <= scc_cnt; i++) printf("%d ", num[i]); puts("");
	for(int i = 0; i < n; i++) {
		for(int v : g[node(i)]) {
			for(int j = 0; j < d; j++) 
				if(sccno[id(i, j)] != sccno[id(v, (j + 1) % d)])
					scc_g[sccno[id(i, j)]].push_back(sccno[id(v, (j + 1) % d)]);
		}
//		for(int v : g[i]) if(sccno[i] != sccno[v]) scc_g[sccno[i]].push_back(sccno[v]);
	}
}
int dfs2(int u) {
	if(dp[u] != -1) return dp[u];
	int res = 0;
	for(int v : scc_g[u]) {
		res = max(res, dfs2(v));
	}
	return dp[u] = res + num[u]; 
}
int main() {
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		g[x].push_back(y);
		/*
		for(int j = 0; j < d; j++) {
			g[id(x, j)].push_back(id(y, (j + 1) % d));
		}
		*/
	}
	for(int i = 0; i < n; i++) scanf("%s", pos[i]);
	/*
	for(int i = 0; i < n * d; i++) {
		printf("%d: ", i);
		for(int v : g[i]) printf("%d ", v); puts("");
	}
	*/
	cal_scc();
//	for(int i = 0; i < n * d; i++) printf("%d ", sccno[i]); puts("");
/*
	for(int i = 0; i <= scc_cnt; i++) {
		printf("%d: ", i);
		for(int v : scc_g[i]) printf("%d ", v); puts("");
	}
*/
	memset(dp, -1, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= scc_cnt; i++) {
		int res = 0;
		tmp.clear();
		for(int v : scc_g[i]) if(!vis[v]) {
			res = max(res, dp[v]);
			vis[v] = 1, tmp.push_back(v);
		}
		for(int v : tmp) vis[v] = 0;
		dp[i] = res + num[i]; 
	}
//	for(int i = 1; i <= scc_cnt; i++) printf("%d ", dp[i]); puts("");
	printf("%d\n", dp[sccno[0]]);
	return 0;
}
