#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, a, b;
		scanf("%d%d%d", &a, &b, &n);
		int ans;
		if(n % 3 == 0) ans = a;
		if(n % 3 == 1) ans = b;
		if(n % 3 == 2) ans = a ^ b;
		printf("%d\n", ans);
	}
	return 0;
}
