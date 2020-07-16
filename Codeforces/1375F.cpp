#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int GetPile(ll x) {
	printf("%lld\n", x); fflush(stdout);
	int a; scanf("%d", &a);
	if(a == 0) exit(0);
	return a - 1;
}
int main() {
	ll a[3]; for(int i = 0; i < 3; i++) scanf("%lld", &a[i]);
	puts("First"); fflush(stdout);

	int p = GetPile(ll(1e11));
	a[p] += ll(1e11);
	int q = GetPile(3 * a[p] - (a[0] + a[1] + a[2]));
	a[q] += 3 * a[p] - (a[0] + a[1] + a[2]);
	GetPile(a[q] - a[p]);
	return 0;
}
