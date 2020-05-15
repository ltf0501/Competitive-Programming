#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10;

int n, k, a[kN];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &k);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		bool flag = 1, t = 0;
		for(int i = 0; i < n; i++) {
			t |= a[i] == k;
		}
		flag &= t;
		t = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 1; j < 3 && i + j < n; j++) {
				t |= a[i] >= k && a[i + j] >= k;
			}
		}
		flag &= (t || n == 1);
		puts(flag ? "yes" : "no");
	}
	return 0;
}
