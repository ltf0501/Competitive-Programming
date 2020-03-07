#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 3e5 + 10;

int n;
int val[kN];
ll mask[kN];
int main() {
	scanf("%d", &n);
	ll sum = 0;
	for(int i = 1; i <= n; i++) scanf("%d%lld", val + i, mask + i), sum += val[i];
	if(sum < 0) {
		for(int i = 1; i <= n; i++) val[i] = -val[i];
	}

	ll ans = 0;
	for(int j = 0; j < 62; j++) {
		ll tot = 0;
		for(int i = 1; i <= n; i++) {
			if(mask[i] == (1LL << j)) tot += val[i]; 
		}
		if(tot > 0) {
			ans |= (1LL << j);
			for(int i = 1; i <= n; i++)
				if(mask[i] & (1LL << j)) val[i] = -val[i];
		}
		for(int i = 1; i <= n; i++) {
			if(mask[i] & (1LL << j)) mask[i] ^= (1LL << j);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
