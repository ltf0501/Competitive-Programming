#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[44];

void pre() { 
	dp[0] = 1, dp[1] = 1, dp[2] = 5;
	for(int i = 3; i <= 40; i++) dp[i] = dp[i - 1] + 4 * dp[i - 2] + 2 * dp[i - 3];
}
int main() {
	pre();
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}
