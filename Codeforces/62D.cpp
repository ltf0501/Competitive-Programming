#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int maxm = 2005;
vector<int> g[maxn];
bool is_edge[maxn][maxn];
int path[maxm];
bool is_bridge[maxn][maxn];
int in[maxn], dfs_clock;
int n, m;
int dfs(int u, int fa) {
	int lowu = in[u] = ++dfs_clock;
	for(int v : g[u]) if(v != fa && is_edge[u][v]) {
		if(!in[v]) lowu = min(lowu, dfs(v, u));
		else if(in[v] < lowu) lowu = in[v];
	}
	if(lowu == in[u] && fa != -1) {
		is_bridge[u][fa] = is_bridge[fa][u] = 1;
	}
	return lowu;
}
void cal() {
	memset(is_bridge, 0, sizeof(is_bridge));
	memset(in, 0, sizeof(in));
	dfs_clock = 0;
	for(int i = 1; i <= n; i++) 
		if(!in[i]) dfs(i, -1);
}
void modify(int x, int y, bool flag) {
	is_edge[x][y] = is_edge[y][x] = flag;
}
int main() {
	scanf("%d%d", &n, &m);
	int x;
	scanf("%d", &x);
	path[0] = x;
	for(int i = 1; i <= m; i++) {
		int y;
		scanf("%d", &y);
		path[i] = y;
		g[x].push_back(y), g[y].push_back(x);
		x = y;
	}
	int ii = -1;
	bool flag = 0;
	for(int i = m - 1; i >= 0; i--) {
		modify(path[i], path[i + 1], 1);
		cal();
		for(int j = path[i + 1] + 1; j <= n; j++) if(is_edge[path[i]][j] && !is_bridge[path[i]][j]) {
			ii = i;
			flag = 1;
		}
		if(flag) break;
	}
	if(!flag) {
		return 0 * puts("No solution");
	}
//	printf("ii = %d\n", ii);
	for(int i = 0; i <= m - 1; i++) modify(path[i], path[i + 1], 1);
	vector<int> ans;
	int cur = path[0];
	for(int i = 0; i <= m - 1; i++) {
		if(i < ii) {
			ans.push_back(path[i + 1]);
			modify(path[i], path[i + 1], 0);
			cur = path[i + 1];
		}
		else {
			cal();
			int cnt = 0;
			int st = (i == ii ? 1 + path[i + 1] : 0);
			for(int j = st; j <= n; j++) if(is_edge[cur][j]) cnt++;
			for(int j = st; j <= n; j++) if(is_edge[cur][j]) {
				if(cnt == 1 || !is_bridge[cur][j]) {
					modify(cur, j, 0);
					ans.push_back(j);
					cur = j;
					break;
				}
			}
		}
	}
	printf("%d ", path[0]);
	for(int x : ans) printf("%d ", x);
	puts("");
	return 0;
}
