#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;

int n;
int a[kN], b[kN], mx[kN];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);

	for(int i = 1; i <= n; i++) {
		a[i] = b[i] + mx[i];
		mx[i + 1] = max(mx[i], a[i]);
	}
	for(int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
	return 0;
}
