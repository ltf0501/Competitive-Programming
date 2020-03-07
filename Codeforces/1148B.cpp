#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 2e5 + 10;
int n, m, k;
ll a[kN], b[kN];
int t_a, t_b;
int main() {
	scanf("%d%d%d%d%d", &n, &m, &t_a, &t_b, &k);
	for(int i = 0; i < n; i++) scanf("%lld", a + i);
	for(int i = 0; i < m; i++) scanf("%lld", b + i);

	if(k >= n || k >= m) return puts("-1"), 0;
	ll ans = 0;
	for(int i = 0; i <= k; i++) {
		int fi = lower_bound(b, b + m, a[i] + t_a) - b;
		if(i + (m - fi) <= k) return puts("-1"), 0;
		int rest = k - i;
		ans = max(ans, b[fi + rest] + t_b);
	}
	printf("%lld\n", ans);
	return 0;
}
