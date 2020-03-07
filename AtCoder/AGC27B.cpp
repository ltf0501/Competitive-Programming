#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
int n, x;
int a[kN];
int64_t sum[kN];
__int128 cal(int k) {
	__int128 res = 0;
	for(int i = 1; i <= n / k; i++) {
		res += __int128(1) * (i == 1 ? 5 : (2 * i + 1)) * (sum[i * k] - sum[(i - 1) * k]);
	}
	return res;
}
int main() {
	scanf("%d%d", &n, &x);
	for(int i = n - 1; i >= 0; i--) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) sum[i + 1] = sum[i] + a[i];
	
	__int128 ans;
	for(int k = 1; k <= n; k++) {
		__int128 tmp = cal(k);
	}
	return 0;
}
