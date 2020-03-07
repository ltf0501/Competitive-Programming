#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const int mod = 998244353;
vector<int> g[maxn];
int n;
int dp[2][maxn], sz[maxn];
int pw[maxn];
int ans;
void dfs(int u, int fa) {
	dp[0][u] = 1;
	sz[u] = 1;
	for(int v : g[u]) if(v != fa) {
		dfs(v, u);
		sz[u] += sz[v];
		dp[1][u] = (2LL * dp[1][u] * (dp[0][v] + dp[1][v]) % mod + 1LL * dp[0][u] * dp[0][v] % mod) % mod;
		dp[0][u] = 1LL * dp[0][u] * (2LL * dp[1][v] + dp[0][v]) % mod;
	}
	ans = (ans + 2LL * dp[1][u] * pw[n - sz[u]]) % mod;
}
int main() {
	pw[0] = 1;
	for(int i = 1; i < maxn; i++) pw[i] = pw[i - 1] * 2 % mod;
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1, -1);
	//for(int i = 1; i <= n; i++) printf("%d %d\n", match[0][i], match[1][i]);
	printf("%d\n", ans);
	return 0;
}
