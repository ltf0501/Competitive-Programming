#include <bits/stdc++.h>
using namespace std;
const int kInf = 1e9;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		vector<int> a(n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		k = min(k, m - 1);
		int ans = 0;
		for(int i = 0; i <= k; i++) {
			int tmp = kInf;
			for(int j = 0; j <= m - 1 - k; j++) {
				int now = max(a[i + j], a[i + j + n - m]);
				tmp = min(tmp, now);
			}
			ans = max(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}
