#include <bits/stdc++.h>
using namespace std;
const int kN = 3605;
const int kMod = 998244353;
bool row[kN], col[kN];
int dp_row[kN][kN], dp_col[kN][kN];
void add(int &a, int b) {
	a += b;
	if(a >= kMod) a -= kMod;
}

int fpow(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = 1LL * res * a % kMod;
		n >>= 1, a = 1LL * a * a % kMod;	
	}
	return res;
}
int Inv(int a) {return fpow(a, kMod - 2);}
int fac[kN], inv[kN];
void pre() {
	fac[0] = 1;
	for(int i = 1; i < kN; i++) fac[i] = 1LL * fac[i - 1] * i % kMod;
	inv[kN - 1] = Inv(fac[kN - 1]);
	for(int i = kN - 2; i >= 0; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % kMod;
}
int C(int n, int m) {
	if(n < 0 || n < m) return 0;
	return 1LL * fac[n] * inv[m] % kMod * inv[n - m] % kMod;
}
int main() {
	pre();
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int tot_row = 0, tot_col = 0;
	for(int i = 0; i < k; i++) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		row[a] = row[c] = 1;
		col[b] = col[d] = 1;
	}

	for(int i = 1; i <= n; i++) tot_row += !row[i];	
	for(int i = 1; i <= m; i++) tot_col += !col[i];

	dp_row[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		dp_row[i][0] = 1;
		for(int j = 1; j <= i / 2; j++) {
			dp_row[i][j] = dp_row[i - 1][j];
			if(i > 1 && !row[i] && !row[i - 1]) add(dp_row[i][j], dp_row[i - 2][j - 1]);
		}
	}

	dp_col[0][0] = 1;
	for(int i = 1; i <= m; i++) {
		dp_col[i][0] = 1;
		for(int j = 1; j <= i / 2; j++) {
			dp_col[i][j] = dp_col[i - 1][j];
			if(i > 1 && !col[i] && !col[i - 1]) add(dp_col[i][j], dp_col[i - 2][j - 1]);
		}
	}
	
	int ans = 0;
	for(int x = 0; x <= tot_col / 2; x++) {
		for(int y = 0; y <= tot_row / 2; y++) {
			int r = 1LL * dp_row[n][y] * C(tot_row - 2 * y, x) % kMod;
			int c = 1LL * dp_col[m][x] * C(tot_col - 2 * x, y) % kMod;
			add(ans, 1LL * r * c % kMod * fac[x] % kMod * fac[y] % kMod);
		}
	}
	printf("%d\n", ans);
	return 0;
}
