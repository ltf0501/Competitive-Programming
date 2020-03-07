#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b;
		scanf("%d%d", &a, &b);
		int g = __gcd(a, b);
		if(g > 1) puts("Infinite");
		else puts("Finite");
	}
	return 0;
}
