#include <bits/stdc++.h>
using namespace std;
const int kN = 8e3 + 10;

int n;
int a[kN], pre[kN];
bool ok[kN];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), pre[i] = pre[i - 1] + a[i];

		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < i - 1; j++) 
				if(pre[i] - pre[j] <= 8000) ok[pre[i] - pre[j]] = 1;
		}
		int ans = 0;
		for(int i = 1; i <= n; i++) ans += ok[a[i]];
		printf("%d\n", ans);
		memset(ok, 0, sizeof(ok));
	} 
	return 0;
}


