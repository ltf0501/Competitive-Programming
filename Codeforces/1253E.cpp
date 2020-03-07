#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e5 + 10;
const int maxn = 85;
int n, m;
int l[maxn], r[maxn];
int dp[maxm];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		int x, s;
		scanf("%d%d", &x, &s);
		x--;
		l[i] = x - s, r[i] = x + s;
	}
	dp[0] = 0;
	for(int i = 1; i <= m; i++) {
		dp[i] = i;
		for(int j = 0; j < n; j++) {
			if(l[j] <= i - 1 && i - 1 <= r[j]) {
				dp[i] = dp[i - 1];
				break;
			}
			if(i > r[j]) {
				int id = max(0, l[j] - (i - r[j] - 1));
				dp[i] = min(dp[i], dp[id] + i - r[j] - 1);	
			}
		}
	}
	printf("%d\n", dp[m]); 
	return 0;
}
