#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
int n, m;
vector<int> g[kN], g2[kN];
int k, a[kN];
int d[kN];
bool vis[kN];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		g[x].push_back(y), g2[y].push_back(x);
	}
	scanf("%d", &k);
	for(int i = 1; i <= k; i++) scanf("%d", a + i);
	queue<int> q;
	q.push(a[k]); vis[a[k]] = 1;
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int v : g2[x]) if(!vis[v]) {
			d[v] = d[x] + 1; vis[v] = 1;
			q.push(v);
		}
	}
	int mn = 0, mx = 0;
	for(int i = 2; i <= k; i++) {
		if(d[a[i]] > d[a[i - 1]] - 1) mn++, mx++;
		else if(d[a[i]] == d[a[i - 1]] - 1) {
			int u = a[i - 1];
			int cnt = 0;
			for(int v : g[u]) if(d[v] == d[a[i]]) cnt++;
			if(cnt >= 2) mx++;
		}
	}
	printf("%d %d\n", mn, mx);
	return 0;
}
