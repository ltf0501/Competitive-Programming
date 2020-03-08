#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 5e5 + 10;
ll a[kN];
int h[kN];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, m; scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) scanf("%lld", a + i);
		for(int i = 1; i <= n; i++) h[i] = uniform_int_distribution<int>(0, INT_MAX)(rng); 
		vector<int> ri(n + 1, 0);
		for(int i = 1, x, y; i <= m; i++) {
			scanf("%d%d", &x, &y);
			ri[y] ^= h[x];
		}

		unordered_map<int, ll> mp;
		for(int i = 1; i <= n; i++) 
			if(ri[i]) mp[ri[i]] += a[i];
		
		ll ans = 0;
		for(auto p : mp) ans = __gcd(ans, p.second);
		printf("%lld\n", ans);
	}	
	return 0;
}
