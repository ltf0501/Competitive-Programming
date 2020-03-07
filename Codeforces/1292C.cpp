#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 3e3 + 10;
int n;
vector<int> g[kN];
int sz[kN][kN], fa[kN][kN];
ll dp[kN][kN];
void dfs(int rt, int u, int ffa) {
	sz[rt][u] = 1;
	for(int v : g[u]) if(v != ffa) {
		dfs(rt, v, u);
		sz[rt][u] += sz[rt][v];
		fa[rt][v] = u;
	}
}
ll Dp(int u, int v) {
	if(u == v) return 0;
	if(u > v) swap(u, v);
	if(dp[u][v] != -1) return dp[u][v];
	return dp[u][v] = 1LL * sz[u][v] * sz[v][u] + max(Dp(u, fa[u][v]), Dp(v, fa[v][u]));
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	for(int i = 1; i <= n; i++) dfs(i, i, -1);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) dp[i][j] = -1;
	ll ans = 0;
	for(int i = 1; i <= n; i++) 
		for(int j = i + 1; j <= n; j++) ans = max(ans, Dp(i, j));

	printf("%lld\n", ans);	
	return 0;
}
