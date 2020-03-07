#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = (int)1e9 + 7;
typedef long long ll;

int n;
int l[maxn], r[maxn];
int p[maxn], q[maxn];
int pre[maxn];
int pw(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = (ll)res * (ll)a % mod;
		a = (ll)a * (ll)a % mod;
		n >>= 1;
	}
	return res;
}
int INV(int a) {return pw(a, mod - 2);}
void add(int& a, int b) {
	a += b;
	if(a >= mod) a -= mod;
	assert(a >= 0 && a < mod);
}
int cal(int i) {
	int tmp = (1 - p[i] - p[i + 1] + mod + mod) % mod;
	assert(tmp >= 0);
	int cc = 0;
	if(min({r[i - 1], r[i], r[i + 1]}) > max({l[i - 1], l[i], l[i + 1]})) {
		int num = min({r[i - 1], r[i], r[i + 1]}) - max({l[i - 1], l[i], l[i + 1]});
		cc = (ll)num * INV((ll)(r[i - 1] - l[i - 1]) * (ll)(r[i] - l[i]) % mod * (ll)(r[i + 1] - l[i + 1]) % mod) % mod; 
	}
	add(tmp, cc);
	return tmp;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &l[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &r[i]), r[i]++;
	q[1] = 1;
	for(int i = 2; i <= n; i++) { 
		if(min(r[i - 1], r[i]) > max(l[i - 1], l[i])) {
			int num = min(r[i - 1], r[i]) - max(l[i - 1], l[i]); 
			p[i] = (ll)num * INV((ll)(r[i] - l[i]) * (ll)(r[i - 1] - l[i - 1]) % mod) % mod;
		}
		q[i] = (1 - p[i] + mod) % mod;
		assert(q[i] >= 0);
	}
	int ans = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++) add(sum, q[i]);
	for(int i = 1; i <= n; i++) {
		int now = sum;
		for(int j = max(1, i - 1); j <= min(i + 1, n); j++)
			now = (now - q[j] + mod) % mod;
		add(ans, (ll)q[i] * (ll)now % mod);
		add(ans, q[i]);
		if(i > 1) add(ans, cal(i - 1));
		if(i + 1 <= n) add(ans, cal(i));
	}
	printf("%d\n", ans);
	return 0;
}
