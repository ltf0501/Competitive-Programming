#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
	int a, b;
	scanf("%lld%lld", &a, &b);
	int n = a + b;
	if(a == 0 || b == 0)return 0 * puts("1");
	int ans = 0;
	for(int l = 1, r; l <= n; l = r + 1) {
		int tmp = n / l;
		r = n / tmp;
		if(tmp > a || tmp > b) continue;
		int la = (a + tmp) / (tmp + 1);
		int lb = (b + tmp) / (tmp + 1);
		int ra = a / tmp;
		int rb = b / tmp;
		if(la > ra || lb > rb) continue;
		int ll = la + lb;
		int rr = ra + rb;
		ll = max(ll, l);
		rr = min(rr, r);
		ans += max(0LL, rr - ll + 1);
	}
	printf("%lld\n", ans);
	return 0;
}
