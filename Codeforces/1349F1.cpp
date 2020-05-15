#include <bits/stdc++.h>
using namespace std;
const int kMod = 998244353;
const int kN = 5e3 + 10;

int fpow(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = 1LL * res * a % kMod;
		n >>= 1, a = 1LL * a * a % kMod;
	}
	return res;
}
int Inv(int a) {return fpow(a, kMod - 2);}
int n;
int fac[kN], invf[kN];
void pre() {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % kMod;
	invf[n] = Inv(fac[n]);
	for(int i = n - 1; i >= 0; i--) invf[i] = 1LL * invf[i + 1] * (i + 1) % kMod;
}
int C(int n, int m) {
	if(n < m) return 0;
	return 1LL * fac[n] * invf[m] % kMod * invf[n - m] % kMod;
}

int dp[kN][kN];
int f[kN];
int add(int a, int b) {
	a += b;
	if(a >= kMod) a -= kMod;
	return a;
}
int main() {
	scanf("%d", &n);
	pre();
	dp[0][0] = 1;
	for(int k = 1; k <= n; k++) {
		for(int i = k; i <= n; i++) dp[i][k] = add(1LL * k * dp[i - 1][k] % kMod, 1LL * (i - k + 1) * dp[i - 1][k - 1] % kMod);
	}
	
	for(int i = 1; i <= n; i++) {
		int ans = 0;
		for(int j = i; j <= n; j++) ans = add(ans, 1LL * fac[n] * invf[j] % kMod * dp[j][i] % kMod);
		printf("%d ", ans);
	}
	return 0;
}
