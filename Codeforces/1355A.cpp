#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second

pii cal(ll n) {
	vector<int> v;
	while(n) {
		v.push_back(n % 10);
		n /= 10;
	}
	int a = 1e9, b = -1e9;	
	for(int x : v) a = min(a, x), b = max(b, x);
	return {a, b};
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll a, k; scanf("%lld%lld", &a, &k);
		k--;
		while(k--) {
			pii res = cal(a);
			if(res.F == 0) break;
			a += 1LL * res.F * res.S;
		}
		printf("%lld\n", a);
	}
	return 0;
}
