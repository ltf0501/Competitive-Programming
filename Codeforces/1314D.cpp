#include <bits/stdc++.h>
using namespace std;
const int kInf = 2e9;
int n, k; 
int dis[85][85];
int dp[85][15], col[85];
int main() { 
	auto start = clock();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++) scanf("%d", &dis[i][j]);
	int ans = kInf;
	int counter = 0;
	while(true) {
		++counter;
		if((counter & 7) == 0) {
			if((clock() - start) / CLOCKS_PER_SEC >= 2.8) break;
		}
		for(int i = 2; i <= n; i++) col[i] = uniform_int_distribution<int>(0, 1)(rng);
		for(int i = 1; i <= n; i++) dp[i][0] = kInf;
		dp[1][0] = 0;
		for(int j = 1; j <= k; j++) {
			for(int i = 1; i <= n; i++) {
				dp[i][j] = kInf;
				if(col[i] != (j & 1)) continue;
				for(int x = 1; x <= n; x++) 
					if(col[i] != col[x]) dp[i][j] = min(dp[i][j], dp[x][j - 1] + dis[x][i]);
			}
		}
		ans = min(ans, dp[1][k]);
	}
	printf("%d\n", ans);
	return 0;
}
