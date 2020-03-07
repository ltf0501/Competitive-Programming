#include <bits/stdc++.h>
using namespace std;
const int kMod = 998244353;
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 1;
	for(int i = 1; i <= n + m; i++) ans = 2 * ans % kMod;
	printf("%d\n", ans);
	return 0;
}
