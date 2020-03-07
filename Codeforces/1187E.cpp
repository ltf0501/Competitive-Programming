#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
vector<int> g[maxn];
int n, sz[maxn];
ll sum, ans;
void dfs1(int u, int fa) {
	sz[u] = 1;
	for(int v : g[u]) if(v != fa) {
		dfs1(v, u);
		sz[u] += sz[v];
	}
	sum += sz[u];
}
void dfs2(int u, int fa, ll now) {
	ans = max(ans, now);
	for(int v : g[u]) if(v != fa) {
		dfs2(v, u, now + (sz[1] - sz[v]) - sz[v]);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs1(1, -1);
//	printf("sum = %lld\n", sum);
	dfs2(1, -1, sum);
	printf("%lld\n", ans);
	return 0;
}
