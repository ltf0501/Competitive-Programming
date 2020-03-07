#include <bits/stdc++.h>
using namespace std;
const int kN = 3e5 + 10;
int n, m;
int fac[kN];
void add(int &a, int b) {
	a += b;
	if(a >= m) a -= m;
}
int main() {
	fac[0] = 1;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % m;
	int ans = 0;
	for(int i = 1; i <= n; i++) add(ans, 1LL * fac[i] * fac[n - i] % m * (n - i + 1) % m * (n - i + 1) % m);
	printf("%d\n", ans);
	return 0;
}
