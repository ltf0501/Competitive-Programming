#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int pw(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = 1LL * res * a % mod;
		n >>= 1, a = 1LL * a * a % mod;
	}
	return res;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = (pw(2, m) - 1) % mod;
	if(ans < 0) ans += mod;
	ans = pw(ans, n);
	printf("%d\n", ans);
	return 0;
}
