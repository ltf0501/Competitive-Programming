#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll fmul(ll a, ll b, ll mod) {
	ll res = 0;
	while(b) {
		if(b & 1) res = (res + a) % mod;
		a = (a + a) % mod, b >>= 1;
	}
	return res;
}
ll fpow(ll a, ll n, ll mod) {
	ll res = 1;
	while(n) {
		if(n & 1) res = fmul(res, a, mod);
		a = fmul(a, a, mod), n >>= 1;
	}
	return res;
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll n, m, k; scanf("%lld%lld%lld", &n, &m, &k);
		printf("%lld\n", fmul(k, fpow((n + 2) >> 1, m, n + 1), n + 1));
	}
	return 0;
}
