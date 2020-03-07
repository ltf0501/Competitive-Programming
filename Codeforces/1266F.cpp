#include <bits/stdc++.h>
using namespace std;
const int kN = 5e5 + 10;
typedef pair<int, int> pii;
#define F first
#define S second
vector<int> g[kN];
vector<int> events[kN];
pii mx[kN], secmx[kN];
int p[kN];
int ans[kN << 1];
int up[kN];
int dp[kN], ch[kN];
int dfs(int u, int fa = 0, int d = 0) {
	p[u] = fa;
	int mxdep = d;
	for(int v : g[u]) if(v != fa) {
		int dd = dfs(v, u, d + 1);
		mxdep = max(mxdep, dd);
		//printf("v = %d, dd - d = %d\n", v, dd - d);
		pii t = {dd - d, v};
		events[dd - d].push_back(u);
		if(mx[u] < t) secmx[u] = mx[u], mx[u] = t;
		else if(secmx[u] < t) secmx[u] = t;
	}
	return mxdep;
}
void dfs2(int u, int fa = 0) {
	//printf("up[%d] = %d\n", u, up[u]);
	for(int v : g[u]) if(v != fa) {
		up[v] = 1 + max(up[u], mx[u].S == v ? secmx[u].F : mx[u].F);
		events[up[v]].push_back(v);
		dfs2(v, u);
	}
}
int main() {
	int n; scanf("%d", &n);
	for(int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1); 
	dfs2(1);
	int mx_dp = 0, t = 0;
	for(int i = 1; i <= n; i++) events[0].push_back(i);
	//for(int i = 1; i <= n; i++) {
	//	printf("events[%d]: ", i);
	//	for(int x : events[i]) printf("%d ", x); puts("");
	//}
	for(int i = n; i >= 0; i--) {
		ans[i * 2 + 1] = mx_dp;
		for(int v : events[i]) {
			ans[i * 2 + 1] = max(ans[i * 2 + 1], dp[v] + 1); 
		}
		for(int v : events[i]) {
			mx_dp = max(mx_dp, ++dp[v]);
			t = max(t, dp[v] + ch[v] - 2);
			if(v != 1) {
				ch[p[v]] = max(ch[p[v]], dp[v]);
				t = max(t, dp[p[v]] + ch[p[v]] - 2);
			}
		}
		ans[i * 2] = max(mx_dp, t); 
	}
	for(int i = 1; i <= n; i++) printf("%d ", max(ans[i], 1)); puts("");
	return 0;
}
