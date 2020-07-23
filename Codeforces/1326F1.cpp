#include <bits/stdc++.h>
using namespace std;
const int kN = 15;

int n;
vector<long long> dp[1 << kN][kN];
long long ans[1 << kN];
char s[kN];

bool edge[kN][kN];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%s", s);
		for(int j = 0; j < n; j++) edge[i][j] = s[j] == '1';
	}

	for(int i = 1; i < (1 << n); i++) {
		int cnt = __builtin_popcount(i) - 1;
		//printf("cnt = %d\n", cnt);
		for(int j = 0; j < n; j++) 
			if(i & (1 << j)) dp[i][j].resize(1 << cnt);
	} 
	for(int i = 0; i < n; i++) dp[1 << i][i][0] = 1;

	for(int i = 1; i < (1 << n); i++) {
		for(int j = 0; j < n; j++) if(i & (1 << j)) {
			for(int k = 0; k < n; k++) if(!(i & (1 << k))) {
				for(int a = 0; a < int(dp[i][j].size()); a++) {
					dp[i | (1 << k)][k][2 * a + edge[j][k]] += dp[i][j][a];
					//printf("dp[%d][%d][%d] = %lld\n", i | (1 << k), k, 2 * a + edge[j][k], dp[i | (1 << k)][k][2 * a + edge[j][k]]);

				}
			}
		}
	}


	for(int i = 0; i < n; i++) {
		//printf("sz = %d\n", int(dp[(1 << n) - 1][i].size()));
		for(int j = 0; j < int(dp[(1 << n) - 1][i].size()); j++) {
			ans[j] += dp[(1 << n) - 1][i][j];
			//printf("ans[%d] += (dp[%d][%d][%d] = %lld)\n", j, (1 << n) - 1, i, j, dp[(1 << n) - 1][i][j]);
		}
	}

	for(int i = 0; i < (1 << (n - 1)); i++) printf("%lld ", ans[i]); puts("");
	return 0;
}
