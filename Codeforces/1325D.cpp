#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll u, v;
	scanf("%lld%lld", &u, &v);
	if(!u && !v) return puts("0"), 0;
	if(u > v || (u & 1) ^ (v & 1)) return puts("-1"), 0;
	if(u == v) return printf("1\n%lld\n", u), 0;

	ll k = (v - u) >> 1;
	ll t = u ^ k;
	if(k + t == v) printf("2\n%lld %lld\n", k, t);
	else printf("3\n%lld %lld %lld\n", u, k, k);
	return 0;
}
