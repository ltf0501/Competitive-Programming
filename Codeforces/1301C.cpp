#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll C(int k) {return 1LL * k * (k + 1) / 2;}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		ll ans = C(n);
		int x = (n - m) / (m + 1);
		int y = (n - m) % (m + 1);
		ans -= 1LL * y * C(x + 1) + 1LL * (m + 1 - y) * C(x); 
		printf("%lld\n", ans);
	}
	return 0;
}
