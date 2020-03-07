#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
const int kN = 2e5 + 10;
int a[kN], num[kN];
int main() {
	int n; scanf("%d", &n);
	ll ans = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), ans += a[i];
	int q; scanf("%d", &q);
	map<pii, int> mp;
	while(q--) {
		int s, t, u; scanf("%d%d%d", &s, &t, &u);
		if(mp.find({s, t}) != mp.end()) {
			int x = mp[{s, t}];
			mp.erase({s, t});
			ans -= max(a[x] - num[x], 0);
			num[x]--;
			ans += max(a[x] - num[x], 0);
		}
		if(u > 0) {
			mp[{s, t}] = u;	
			ans -= max(a[u] - num[u], 0);
			num[u]++;
			ans += max(a[u] - num[u], 0);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
