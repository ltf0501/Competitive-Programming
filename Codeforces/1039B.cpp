#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ff fflush(stdout)

bool query(ll l, ll r) {
	printf("%lld %lld\n", l, r); ff;
	char c[5]; scanf("%s", c);
	if(c[0] == 'B') exit(0);
	if(c[0] == 'N') return 0;
	if(c[0] == 'Y' && l == r) exit(0);
	return 1;
}

int main() {
	ll n; int k;
	scanf("%lld%d", &n, &k);
	ll L = 1, R = n;
	mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
	while(true) {
		ll l = L, r = R;
		while(r - l + 1 > 4 * k) {
			ll m = (l + r) >> 1;
			if(query(l, m)) l = max(1LL, l - k), r = min(n, m + k);
			else l = max(1LL, m + 1 - k), r = min(n, r + k);
		}
		ll x = uniform_int_distribution<ll>(l, r)(rng);
		query(x, x);
		L = max(1LL, l - k), R = min(n, r + k);
	}
    return 0;
}

