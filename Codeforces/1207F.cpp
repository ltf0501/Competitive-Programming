#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
const int SZ = 710;
int sum[SZ + 5][SZ + 5];
int a[maxn];
int main() {
	int q;
	scanf("%d", &q);
	while(q--) {
		int type, x,y;
		scanf("%d%d%d", &type, &x, &y);
		if(type == 1) {
			x--;
			for(int i = 1; i <= SZ; i++) sum[i][x % i] += y;
			a[x] += y;
		}
		else {
			y = (y - 1 + x) % x;
			if(x > SZ) {
				int ans = 0;
				for(int i = y; i < 500000; i += x) ans += a[i];
				printf("%d\n", ans);
			}
			else {
				printf("%d\n", sum[x][y]);
			}
		}
	}
	return 0;
}
