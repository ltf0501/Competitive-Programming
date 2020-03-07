#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10;

int n;
vector<int> g[kN];
int in[kN], out[kN], dfs_clock;
int dep[kN];
int anc[20][kN];
void dfs(int u, int fa = 0, int d = 0) {
	in[u] = ++dfs_clock;
	anc[0][u] = fa, dep[u] = d;
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
int dis(int x, int y) {return dep[x] + dep[y] - 2 * dep[LCA(x, y)];}
int main() {
	scanf("%d", &n);
	for(int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1); out[0] = dfs_clock;
	for(int j = 1; j <= 17; j++)
		for(int i = 1; i <= n; i++) anc[j][i] = anc[j - 1][anc[j - 1][i]];

	int q;
	scanf("%d", &q);
	while(q--) {
		int x, y, a, b, k;
		scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
		int predis = dis(a, b);
		if(predis <= k && (k - predis) % 2 == 0) puts("YES");
		else {
			int cur_dis = dis(x, a) + 1 + dis(b, y);
			if(cur_dis <= k && (k - cur_dis) % 2 == 0) puts("YES");
			else {
				cur_dis = dis(x, b) + 1 + dis(a, y);
				if(cur_dis <= k && (k - cur_dis) % 2 == 0) puts("YES");
				else puts("NO");
			}
		}
	}
	return 0;
}
