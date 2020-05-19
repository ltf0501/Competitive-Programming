#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 1e5 + 10;
const ll kInf = 1e18 + 10;

int n;
int a[kN];
ll pre[kN];
int A, R, M;

ll cal(ll x) {
	int k = upper_bound(a + 1, a + n + 1, x) - a - 1;	
	ll P = x * k - pre[k];
	ll Q = (pre[n] - pre[k]) - (n - k) * x;
	ll res;
	if(P >= Q) res = 1LL * A * (P - Q) + 1LL * M * Q;
	else res = 1LL * R * (Q - P) + 1LL * M * P;
	return res;
}
int main() {
	scanf("%d%d%d%d", &n, &A, &R, &M);
	M = min(M, A + R);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];

	ll ans = kInf;
	for(int i = 1; i <= n; i++) ans = min(ans, cal(a[i]));
	ans = min(ans, cal(pre[n] / n)); 
	ans = min(ans, cal((pre[n] + n - 1) / n));
	printf("%lld\n", ans);
	return 0;
}
