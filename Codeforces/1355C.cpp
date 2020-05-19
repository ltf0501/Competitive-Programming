#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	long long ans = 0;
	for(int i = 1; i <= int(1e6); i++) {
		int x = i - c, y = i - b;
		x = max(x, a), y = min(y, b);
		x = y - x + 1;
		if(x <= 0) continue;
		y = min(i - 1, d) - c + 1;
		if(y <= 0) continue;
		ans += 1LL * x * y;
	}
	printf("%lld\n", ans);
	return 0;
}
