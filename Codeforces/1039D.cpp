#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10;
const int B = 1300;
typedef pair<int, int> pii;
#define F first
#define S second
int n;
vector<int> g[kN], gg[kN];
pii dp[kN];
int ans[kN];
int in[kN], dfs_clock;
void dfs(int u, int fa) {
	in[u] = ++dfs_clock;
	for(int v : g[u]) 
		if(v != fa) dfs(v, u);
}
int solve(int k) {
	for(int u = n; u >= 1; u--) {
		pii mx = {-1, -1};
		dp[u] = {0, 0};
		for(int v : gg[u]) {
			dp[u].F += dp[v].F;
			dp[u].S = max(dp[u].S, dp[v].S);

			if(dp[v].S > mx.F) mx.S = mx.F, mx.F = dp[v].S;
			else if(dp[v].S > mx.S) mx.S = dp[v].S;
		}
		if(++dp[u].S == k) dp[u] = {dp[u].F + 1, 0};
		else if(mx.S != -1 && mx.F + mx.S + 1 >= k) dp[u] = {dp[u].F + 1, 0};
	}
	return dp[1].F;
}
int main() {
	scanf("%d", &n);
	for(int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}

	dfs(1, 0);
	for(int u = 1; u <= n; u++) {
		int uu = in[u];
		for(int v : g[u]) {
			int vv = in[v];
			if(uu < vv) gg[uu].push_back(vv);
		}
	}
	for(int i = 1; i <= min(n, B); i++) {
		ans[i] = solve(i);
	}
	if(n > B) {
		for(int i = ans[B], pre = B + 1; i >= 0; i--) {
			int l = pre - 1, r = n + 1;
			while(r - l > 1) {
				int m = (l + r) >> 1;
				if(solve(m) < i) r = m;
				else l = m;
			}
			while(pre < r) ans[pre++] = i;
		}
	}
	for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}
