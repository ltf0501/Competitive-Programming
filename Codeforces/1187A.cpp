#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int a, b, n;
		scanf("%d%d%d", &n, &a, &b);
		if(a > b) swap(a, b);
		int ans = n - a + 1;
		printf("%d\n", ans);
	}
	return 0;
}
