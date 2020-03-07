#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
vector<int> g[maxn];
int n, m;
int col[maxn];
int com[maxn], len[maxn];
bool dfs(int u, int c, int s) {
	col[u] = c;
	com[u] = s;
	for(int v : g[u]) {
		if(!col[v]) {
			if(!dfs(v, 3 - c, s)) return 0;
		}
		else if(col[v] == c) return 0;
	}
	return 1;
}
bool vis[maxn];
int dis[maxn];
void cal(int u) {
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++) dis[i] = maxn;
	dis[u] = 0;
	queue<int> q;
	q.push(u);
	vis[u] = 1;
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int v : g[x]) if(!vis[v]) {
			dis[v] = dis[x] + 1;
			vis[v] = 1;
			q.push(v);
		} 
	}
	int tmp = 0;
	/*
	printf("u = %d\n", u);
	for(int i = 1; i <= n; i++) printf("%d ", dis[i]); puts("");
	*/
	for(int i = 1; i <= n; i++) 
		if(vis[i]) tmp = max(tmp, dis[i]);
	len[com[u]] = max(len[com[u]], tmp);
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++) 
		if(!col[i] && !dfs(i, 1, ++cnt)) return 0 * puts("-1");
	for(int i = 1; i <= n; i++) cal(i);
	int ans = 0;
	for(int i = 1; i <= cnt; i++) ans += len[i];
	printf("%d\n", ans);
	return 0;
}
