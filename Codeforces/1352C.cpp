#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, k; scanf("%d%d", &n, &k);
		int a = k / (n - 1), b = k % (n - 1);
		printf("%d\n", a * n + b - (b == 0));
	}
	return 0;
}
