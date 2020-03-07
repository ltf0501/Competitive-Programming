#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll x; scanf("%lld", &x);
		if(x < 15) {puts("NO"); continue;}
		int a = x % 14;
		if(1 <= a && a <= 6) puts("YES");
		else puts("NO");
	}
	return 0;
}
