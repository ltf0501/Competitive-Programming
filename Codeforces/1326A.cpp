#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		if(n == 1) {
			puts("-1");
			continue;
		}
		printf("2");
		for(int i = 0; i < n - 1; i++) printf("3"); puts("");
	}
	return 0;
}
