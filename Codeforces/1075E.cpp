#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int x[maxn], y[maxn], id[4];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		if(x[i] < x[id[0]]) id[0] = i;
		if(x[i] > x[id[1]]) id[1] = i;
		if(y[i] < y[id[2]]) id[2] = i;
		if(y[i] > y[id[3]]) id[3] = i;
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, abs(x[i] - x[id[0]]) + abs(y[i] - y[id[2]]));
		ans = max(ans, abs(x[i] - x[id[1]]) + abs(y[i] - y[id[2]]));
		ans = max(ans, abs(x[i] - x[id[0]]) + abs(y[i] - y[id[3]]));
		ans = max(ans, abs(x[i] - x[id[1]]) + abs(y[i] - y[id[3]]));
	}
	printf("%d ", 2 * ans);
	for(int i = 4; i <= n; i++) printf("%d ", 2 * (x[id[1]] - x[id[0]] + (y[id[3]] - y[id[2]]))); puts("");
	return 0;
}
