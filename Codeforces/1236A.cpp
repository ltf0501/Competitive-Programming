#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
	scanf("%d%d%d", &a, &b, &c);
	int ans = 0;
	int x = min(b, c / 2);
	ans += x;
	b -= x, c -= 2 * x;
	x = min(a, b / 2);
	ans += x;
	printf("%d\n", ans * 3);
	}
	return 0;
}
