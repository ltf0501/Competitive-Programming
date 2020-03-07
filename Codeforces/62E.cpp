#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const ll INF = 1e14;
ll dp[1 << 5], dp2[1 << 5];
int n, m;
int row[5][maxn], col[5][maxn];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i < m; i++)
		for(int j = 0; j < n; j++) scanf("%d", &row[j][i]);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++) scanf("%d", &col[j][i]);
	for(int mask = 1; mask < (1 << n); mask++) dp2[mask] = INF;
	for(int i = 1; i < m; i++) {
		for(int mask = 0; mask < (1 << n); mask++) {
			ll tmp = INF;
			ll sum = 0;
			for(int a = 0; a < n; a++) {
				int aa = (a + 1) % n;
				if(((mask & (1 << a)) != 0) ^ ((mask & (1 << aa)) != 0)) sum += col[a][i];
			}
			for(int mask2 = 0; mask2 < (1 << n); mask2++) {
				ll ssum = 0;
				for(int a = 0; a < n; a++) {
					if((mask & (1 << a)) ^ (mask2 & (1 << a))) ssum += row[a][i]; 
				}
				tmp = min(tmp, sum + ssum + dp2[mask2]);
			}
			dp[mask] = tmp;
		}
//		for(int mask = 0; mask < (1 << n); mask++) printf("%lld ", dp[mask]);puts("");
		for(int mask = 0; mask < (1 << n); mask++) dp2[mask] = dp[mask];
	}
	ll ans = dp[(1 << n) - 1];
//	for(int mask = 0; mask < (1 << n); mask++) ans = min(ans, dp[mask]);
	printf("%lld\n", ans);
	return 0;
}
