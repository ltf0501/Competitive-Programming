#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
const int kN = 2510;
pii p[kN];
ll cross(pii a, pii b) {
	return 1LL * a.F * b.S - 1LL * a.S * b.F;
}
bool cmp(pii a, pii b) {
	int flag_a = a < pii(0, 0);
	int flag_b = b < pii(0, 0);
	if(flag_a != flag_b) return flag_a < flag_b;
	return cross(a, b) > 0;
}
ll C3(int n) {
	return 1LL * n * (n - 1) * (n - 2) / 6;
}
ll C5(int n) {
	return 1LL * n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 120;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d%d", &p[i].F, &p[i].S);
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		vector<pii> v;
		ll sum = 0;
		for(int j = 0; j < n; j++) 
			if(i != j) v.emplace_back(p[j].F - p[i].F, p[j].S - p[i].S);
		sort(v.begin(), v.end(), cmp);
		//for(auto p : v) printf("(%d, %d) ", p.F, p.S); puts("");
		for(int j = 0, k = 1; j < n - 1; j++) {
			while(k < j + n - 1 && cross(v[j], v[k % (n - 1)]) >= 0) k++;
			//printf("j = %d, k = %d\n", j, k);
			sum += C3((k - j - 1 + n - 1) % (n - 1));
		}
		//printf("%lld\n", sum);
		ans += sum;
	}
	printf("%lld\n", 5 * C5(n) - ans);
	return 0;
}
