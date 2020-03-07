#include <bits/stdc++.h>
using namespace std;

int main() {

	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	long long int ans = 2LL * c + 1LL * min(a, b) + 1LL * min(max(a, b), min(a, b) + 1);
	printf("%lld\n", ans);
	return 0;
}
