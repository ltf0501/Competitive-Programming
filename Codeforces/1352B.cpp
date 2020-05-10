#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, k; scanf("%d%d", &n, &k);
		if(n < k) {
			puts("NO");
			continue;
		}
		if((n & 1) && (k % 2 == 0)) {
			puts("NO");
			continue;
		}

		if((n & 1) && (k & 1)) {
			puts("YES");
			for(int i = 1; i < k; i++) printf("1 ");
			printf("%d\n", n - k + 1);
			continue;
		}
		if((k & 1) && n < 2 * k) {
			puts("NO"); continue;
		}
		if((n % 2 == 0) && (k % 2 == 0)) {
			puts("YES");
			for(int i = 1; i < k; i++) printf("1 ");
			printf("%d\n", n - k + 1);
			continue;
		}
		puts("YES");
		for(int i = 1; i < k; i++) printf("2 ");
		printf("%d\n", n - 2 * k + 2);
	}
	return 0;
}
