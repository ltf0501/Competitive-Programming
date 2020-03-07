#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 2e5 + 10;
int a[kN], b[kN];
vector<int> v[(int)1e6 + 10];
int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = a[i] - i;
	for(int i = 1; i <= n; i++) v[b[i] + kN].push_back(i);
	ll ans = 0;
	for(int i = 0; i < (int)1e6 + 10; i++) {
		ll tmp = 0;
		for(int x : v[i]) tmp += a[x];
		ans = max(ans, tmp);
	}
	printf("%lld\n", ans);
	return 0;
}
