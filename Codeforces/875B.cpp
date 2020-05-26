#include <bits/stdc++.h>
using namespace std;
const int kN = 3e5 + 10;
int a[kN];
int main() {
	int n; scanf("%d", &n);
	int now = n;
	printf("1 ");
	for(int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		a[x] = 1;
		while(a[now]) now--;
		printf("%d ", i - (n - now) + 1);
	}
	puts("");
	return 0;
}
