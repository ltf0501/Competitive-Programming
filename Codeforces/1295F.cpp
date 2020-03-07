#include <bits/stdc++.h>
using namespace std;
#define ALL(v) v.begin(), v.end()
const int kMod = 998244353;
const int kN = 55;
int dp[kN][kN << 1];
int n;
int l[kN], r[kN];
int l_id[kN], r_id[kN];
int pw(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = 1LL * res * a % kMod;
		a = 1LL * a * a % kMod, n >>= 1;
	}
	return res;
}
int Inv(int a) {return pw(a, kMod - 2);}
void add(int &a, int b) {
	a += b;
	if(a >= kMod) a -= kMod;
}
int C(int n, int m) {
	if(m > n - m) m = n - m;
	//printf("n = %d, m = %d\n", n, m);
	int a = 1, b = 1;
	for(int i = 0; i < m; i++) {
		a = 1LL * a * (n - i) % kMod;
		b = 1LL * b * (i + 1) % kMod;
	}
	return 1LL * a * Inv(b) % kMod;
}
int H(int n, int m) {
	return C(n + m - 1, m);
}
int main() {
	scanf("%d", &n);
	vector<int> v;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", l + i, r + i); r[i]++;
		v.push_back(l[i]), v.push_back(r[i]);
	}
	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());
	for(int i = 1; i <= n; i++) {
		l_id[i] = lower_bound(ALL(v), l[i]) - v.begin() + 1;
		r_id[i] = lower_bound(ALL(v), r[i]) - v.begin() + 1;
	}
	//printf("v: ");
	//for(int x : v) printf("%d ", x); puts("");
	int m = int(v.size()) - 1;
	dp[0][0] = 1;
	for(int j = 0; j < m; j++) {
		for(int i = 0; i <= n; i++) if(dp[i][j]) {
			for(int k = 0; i + k <= n; k++) {
				if(k && (l_id[i + k] > m - j || r_id[i + k] <= m - j)) break;
				//dp[i + k][j + 1] += dp[i][j] * H(r[j + 1] - l[j + 1], k) 
				//printf("j = %d, i = %d, k = %d, dp[%d][%d] += %d\n", j, i, k, i + k, j + 1, 1LL * dp[i][j] * H(v[j + 1] - v[j], k) % kMod);
				add(dp[i + k][j + 1], 1LL * dp[i][j] * H(v[m - j] - v[m - 1 - j], k) % kMod);	
			}
		}
	}
	//printf("dp = %d\n", dp[n][m]);
	int ans = 1;
	for(int i = 1; i <= n; i++) ans = 1LL * ans * (r[i] - l[i]) % kMod;
	ans = 1LL * dp[n][m] * Inv(ans) % kMod;
	printf("%d\n", ans);
	return 0;
}
