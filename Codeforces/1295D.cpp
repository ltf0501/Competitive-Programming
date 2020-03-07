#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		ll a, m;
		scanf("%lld%lld", &a, &m);
		ll g = __gcd(a, m);
		a /= g, m /= g;
		ll M = m;
		vector<ll> prime;
		for(ll i = 2;i * i <= M; i++) {
			if(M % i == 0) {
				prime.push_back(i);
				while(M % i == 0) M /= i;
			}
		}
		if(M != 1) prime.push_back(M);
		ll ans = m;
		for(ll p : prime) ans = ans / p * (p - 1);
		printf("%lld\n", ans);
	}
	return 0;
}
