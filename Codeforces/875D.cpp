#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
typedef long long ll;

int n;
int a[kN];
int id[kN];
set<int> s;

int le[30][kN], ri[30][kN]; // 0 ~ 29
int L[kN], R[kN];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for(int j = 0; j < 30; j++) {
		int cur = 0;
		for(int i = 1; i <= n; i++) {
			le[j][i] = cur;
			if(a[i] & (1 << j)) cur = i;
		}
		cur = n + 1;
		for(int i = n; i >= 1; i--) {
			ri[j][i] = cur;
			if(a[i] & (1 << j)) cur = i;
		}
	}

	for(int i = 1; i <= n; i++) {
		vector<int> v;
		for(int j = 0; j < 30; j++)
			if(!(a[i] & (1 << j))) v.push_back(j);
		L[i] = 0;
		for(int j : v) L[i] = max(L[i], le[j][i]);
	}
	for(int i = 1; i <= n; i++) {
		vector<int> v;
		for(int j = 0; j < 30; j++)
			if(!(a[i] & (1 << j))) v.push_back(j);
		R[i] = n + 1;
		for(int j : v) R[i] = min(R[i], ri[j][i]);
	}
	//printf("L: ");	
	//for(int i = 1; i <= n; i++) printf("%d ", L[i]); puts("");
	//printf("R: ");	
	//for(int i = 1; i <= n; i++) printf("%d ", R[i]); puts("");
	
	for(int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, [&](int i, int j) {
			return a[i] != a[j] ? a[i] > a[j] : i < j;
			});
	s.insert(0); s.insert(n + 1);
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		int ii = id[i];	
		auto it = s.lower_bound(ii);
		int l = max(L[ii], *prev(it));
		int r = min(R[ii], *it);
		ans += 1LL * (ii - l) * (r - ii);
		s.insert(ii);
	}
	//printf("ans = %lld\n", ans);
	ans = 1LL * n * (n + 1) / 2 - ans;
	printf("%lld\n", ans);
	return 0;
}
