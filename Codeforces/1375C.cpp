#include <bits/stdc++.h>
using namespace std;
const int kN = 3e5 + 10;

int a[kN];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		puts(a[1] < a[n] ? "YES" : "NO");
	}
	return 0;
}
