#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10;
const int kInf = 1e9 + 10;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n + 5);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		a[0] = a[n + 1] = a[n + 2] = 0;
		bool flag = 1;
		for(int i = 1; i <= n; i++) if(a[i] != -1) {flag = 0; break;}
		if(flag) {puts("0 0"); continue;}
		int mn = kInf, mx = -kInf;
		for(int i = 1; i <= n; i++) if(a[i] != -1) {
			if(a[i - 1] == -1 || a[i + 1] == -1) mx = max(mx, a[i]), mn = min(mn, a[i]);
		}
		int ans = (mn + mx) / 2;
		int tmp = -kInf;
		for(int i = 1; i < n; i++) {
			if(a[i] != -1 && a[i + 1] != -1) tmp = max(tmp, abs(a[i] - a[i + 1]));
		}
		printf("%d %d\n", max({tmp, mx - ans, ans - mn}), ans);
	}
	return 0;
}
