#include <bits/stdc++.h>
using namespace std;
const int kN = 105;
int a[kN];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) {
			if(i & 1) printf("%d ", abs(a[i]));
			else printf("%d ", -abs(a[i]));
		}
		puts("");
	}
	return 0;
}
