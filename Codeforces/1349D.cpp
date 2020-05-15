#include <bits/stdc++.h>
using namespace std;
const int kMod = 998244353;
const int kN = 3e5 + 10;

int n;
int a[kN], f[kN];

int fpow(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = 1LL * res * a % kMod;
		n >>= 1, a = 1LL * a * a % kMod;
	}
	return res;
}
int Inv(int a) {return fpow(a, kMod - 2);}

int add(int a, int b) {
	a += b;
	if(a >= kMod) a -= kMod;
	return a;
}
int sub(int a, int b) {
	a -= b;
	if(a < 0) a += kMod;
	return a;
}
int main() {
	scanf("%d", &n);
	int T = 0;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), T += a[i];

	f[0] = n - 1;
	for(int i = 1; i < T; i++) { // f_k = 1 + (T - k) / T * ((n - 2) / (n - 1) * f_k) + k / T * (f_{k - 1} + f_k)
		f[i] = 1LL * (n - 1) * Inv(T - i) % kMod * add(T, 1LL * i * f[i - 1] % kMod) % kMod;
	} 
	for(int i = T - 2; i >= 0; i--) f[i] = add(f[i], f[i + 1]);

	int ans = 0;
	for(int i = 0; i < n; i++) ans = add(ans, f[a[i]]); 
	ans = sub(ans, 1LL * f[0] * (n - 1) % kMod);
	ans = 1LL * ans * Inv(n) % kMod;
	printf("%d\n", ans);
	return 0;
}
