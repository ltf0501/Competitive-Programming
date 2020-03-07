#include <stdio.h>

#define kN 10010
#define kInf 1000000000 
int a[kN];
int sum[kN];
int dp[kN];
int min(int x, int y) {
	if(x >= y) return y;
	else return x;
}
int main() {
	int n;
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		int m;
		scanf("%d", &m);
		for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
		for(int i = 1; i <= n; i++) {
			dp[i] = kInf;
			for(int j = i - 1; j >= 0; j--) {
				int x = sum[i] - sum[j];
				if(x > m) break;
				dp[i] = min(dp[i], dp[j] + (m - x) * (m - x));
			}
		}
		if(sum[n] >= dp[n]) printf("%d\n", sum[n] - dp[n]);
		else puts("QQ");
	}
	return 0;
}
