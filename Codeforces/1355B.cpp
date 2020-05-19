#include <bits/stdc++.h>
using namespace std;
const int kN = 3e5 + 10;

int n;
int a[kN];
int cnt[kN];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]), cnt[a[i]]++;
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			ans += cnt[i] / i;
			cnt[i + 1] += cnt[i] % i;
		}
		printf("%d\n", ans);
		for(int i = 1; i <= n + 1; i++) cnt[i] = 0;
	}
	return 0;
}
