#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10;
int n, q;
bool vis[2][kN];
int main() {
	scanf("%d%d", &n, &q);
	int num = 0;
	while(q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		int d = vis[x][y] ? -1 : 1;
		vis[x][y] ^= 1;
		for(int i = -1; i <= 1; i++) {
			if(y + i < 0 || y + i >= n) continue;
			if(vis[x ^ 1][y + i]) num += d;
		}
		puts(num ? "No" : "Yes");
	}
	return 0;
}
