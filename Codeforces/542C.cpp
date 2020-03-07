#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 205;
int f[maxn * 10][maxn], num[maxn];
bool vis[maxn];
ll lcm(ll a, ll b) {
	return a / __gcd(a, b) * b;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &f[1][i]);
	for(int j = 2; j <= 10 * n; j++)
		for(int i = 1; i <= n; i++) f[j][i] = f[1][f[j - 1][i]];
	ll ans = 1;
	int mx = 0;
	for(int i = 1; i <= n; i++) {
		int t = 1;
		while(f[t][i] != f[t << 1][i]) t++;
		int sec_t = t + 1;
		while(f[sec_t][i] != f[sec_t << 1][i]) sec_t++;
		mx = max(mx, t);
		ans = lcm(ans, sec_t - t);
	}
	ll tmp = ans;
	while(ans < mx) ans += tmp;
	printf("%lld\n", ans);
	return 0;
}
