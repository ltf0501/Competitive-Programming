#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10;

int n, T;
vector<int> g[kN];
int deg[kN];

vector<pair<int, int>> ans;
void dfs(int u, int fa, int k) {
	ans.emplace_back(u, k);		
	int cur = k;
	bool flag = 0;
	int d = deg[u] - 1;
	for(int v : g[u]) if(v != fa) {
		if(cur == T) ans.emplace_back(u, cur = T - d - 1), flag = 1;
		dfs(v, u, cur + 1);
		ans.emplace_back(u, cur + 1);
		cur++;
	}
	if(!flag && u != 1) ans.emplace_back(u, k - 1);
}
int main() {
	scanf("%d", &n);
	for(int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
		deg[x]++, deg[y]++;
	}
	for(int i = 1; i <= n; i++) T = max(T, deg[i]);
	deg[1]++;
	dfs(1, -1, 0);
	printf("%d\n", ans.size());
	for(auto p : ans) printf("%d %d\n", p.first, p.second);
	return 0;
}
