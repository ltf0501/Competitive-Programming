#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
struct E {
	int x, y, d;
	bool operator < (const E& r) const {
		return d > r.d;
	}
};
int cnt[maxn];
vector<E> edges;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		edges.clear();
		int n, k;
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++) cnt[i] = 0;
		for(int i = 1; i < n; i++) {
			int x, y, d;
			scanf("%d%d%d", &x, &y, &d);
			edges.push_back({x, y, d});
		}
		ll ans = 0;
		sort(edges.begin(), edges.end());
		for(auto e : edges) {
			if(cnt[e.x] >= k || cnt[e.y] >= k) continue;
			cnt[e.x]++, cnt[e.y]++;
			ans += e.d;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
