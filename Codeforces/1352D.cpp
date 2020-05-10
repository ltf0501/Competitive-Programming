#include <bits/stdc++.h>
using namespace std;
const int kN = 1e3 + 10;

int n;
int x[kN];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
		int a = 0, b = 0, l = 1, r = n;
		bool flag = 1;
		int prev = 0, move = 0;
		while(true) {
			int now = 0;
			if(flag) {
				while(l <= r && now <= prev) {
					now += x[l++];
				}
				a += now;
			}
			else {
				while(l <= r && now <= prev) {
					now += x[r--];
				}
				b += now;
			}
			flag ^= 1;
			move++;
			prev = now;
			if(l > r) break;
		}
		printf("%d %d %d\n", move, a, b);
	} 
	return 0;
}
