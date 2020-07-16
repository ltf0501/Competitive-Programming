#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;

int n;
vector<int> g[kN];
int dep[kN];
void dfs(int u, int fa = -1, int d = 0) {
	dep[u] = d;
	for(int v : g[u]) 
		if(v != fa) dfs(v, u, d + 1);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1);

	int cnt[2] = {};
	for(int i = 1; i <= n; i++) cnt[dep[i] & 1]++;
	printf("%d\n", min(cnt[0], cnt[1]) - 1);
	return 0;
}
