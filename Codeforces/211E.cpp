#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
vector<int> g[maxn];
int sz[maxn];
bool f[maxn], is[maxn];
int n;
int dfs(int u, int fa) {
	sz[u] = 1;
	for(int v : g[u]) if(v != fa)
		sz[u] += dfs(v, u);
	memset(f, 0, sizeof(f));
	f[0] = 1;
	int sum = 0;
	for(int v : g[u]) if(v != fa) {
		for(int j = sum; j >= 0; j--) f[j + sz[v]] |= f[j];
		sum += sz[v];
	}
	for(int j = sum; j >= 0; j--) f[j + n - sz[u]] |= f[j];
	for(int i = 1; i < n - 1; i++) is[i] |= f[i];
	return sz[u];
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1, -1);
	vector<int> ans;
	for(int i = 1; i < n - 1; i++) 
		if(is[i]) ans.push_back(i);
	printf("%d\n", (int)ans.size());
	for(int x : ans) printf("%d %d\n", x, n - 1 - x);
	return 0;
}
