#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int p[maxn];
int a, b, x, y;
ll k;
ll g;
ll cal(int m) {
	ll res = 0;
	int id = 0;
	for(int i = 1; 1LL * g * i <= m; i++) 
		res += 1LL * p[++id] / 100 * (x + y); 
	for(int i = 1; 1LL * a * i <= m; i++)
		if((a * i) % g != 0) res += 1LL * p[++id] / 100 * x; 
	for(int i = 1; 1LL * b * i <= m; i++)
		if((b * i) % g != 0) res += 1LL * p[++id] / 100 * y;
	printf("m = %d, res = %lld\n", m, res);
	return res;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
		sort(p + 1, p + n + 1, [&](int a, int b) {return a > b;});
		scanf("%d%d%d%d", &x, &a, &y, &b);
		if(x < y) swap(a, b), swap(x, y);
		g = 1LL * a * b / __gcd((ll)a, (ll)b);
		scanf("%lld", &k);
		int l = 1, r = n + 1;
		int ans = n + 1;
		while(l <= r) {
			printf("l = %d, r = %d\n", l, r);
			int m = (l + r) >> 1;
			if(cal(m) >= k) r = m - 1, ans = m;
			else l = m + 1;
		}
		ans = (ans == n + 1) ? -1 : ans;
		printf("ans = %d\n", ans);
	}
	
	return 0;
}
