#include <bits/stdc++.h>
using namespace std;
const int kN = 505;
const int kMod = 998244353;
int p[kN], pos[kN];
int low[kN][kN];
int dp[kN][kN];
bool vis[kN][kN];
void add(int &a, int b) {
	a += b;
	if(a >= kMod) a -= kMod;
}
int dfs(int l, int r) {
	if(l == r) return 1;
	if(vis[l][r]) return dp[l][r];
	vis[l][r] = 1;
	int le = 0, ri = 0;
	int x = pos[low[l][r]];
	//printf("l = %d, r = %d, x = %d\n", l, r, x);
	for(int i = l; i <= x; i++) add(le, 1LL * dfs(l, i) * dfs(i, x) % kMod);
	for(int i = x + 1; i <= r; i++) add(ri, 1LL * dfs(x + 1, i) * dfs(i, r) % kMod);
	//printf("dp[%d][%d] = %d, le = %d, ri = %d\n", l, r, 1LL * le * ri % kMod, le, ri);
	return dp[l][r] = 1LL * le * ri % kMod;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", p + i), p[i]--;
	for(int i = 0; i < n; i++) pos[p[i]] = i;	
	for(int i = 0; i < n; i++) {
		int mn = n + 1;
		for(int j = i; j < n; j++) {
			mn = min(mn, p[j]);
			low[i][j + 1] = mn;
		}
	}
	printf("%d\n", dfs(0, n));
	return 0;
}
