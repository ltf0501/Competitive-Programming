#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long ll;
int phi[maxn];
vector<int> p;
void pre() {
	for(int i = 1; i < maxn; i++) phi[i] = i;
	for(int i = 2; i < maxn; i++) {
		if(phi[i] == i) phi[i] = i - 1, p.push_back(i);
		for(int j = 0; j < (int)p.size() && 1LL * i * p[j] < maxn; j++) {
			if(i % p[j] != 0) phi[i * p[j]] = phi[i] * (p[j] - 1);
			if(i % p[j] == 0) {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
		}
	}
//	for(int i = 1; i <= 30; i++) printf("%d: %d\n", i, phi[i]);
}
int main() {
	pre();
	int n, k;
	scanf("%d%d", &n, &k);
	if(k == 1) return 0 * puts("3");
	sort(phi + 1, phi + n + 1);
	ll ans = 0;
	for(int i = 1; i <= k + 2; i++) ans += phi[i];
	printf("%lld\n", ans);
	return 0;
}
