#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;

int n, m;
struct Princess {
	int a, b, w;
	bool operator < (const Princess &r) const {
		return w > r.w;
	}
}x[kN];
int p[kN], sz[kN];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) scanf("%d%d%d", &x[i].a, &x[i].b, &x[i].w);
	sort(x + 1, x + m + 1);
	for(int i = 1; i <= n; i++) p[i] = i;
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		int u = find(x[i].a), v = find(x[i].b);
		if(u != v) {	
			if(sz[u] + sz[v] <= 1) {
				ans += x[i].w;
				sz[u] += sz[v];
				p[v] = u;
			}
		}
		else {
			if(sz[u] == 0) {
				sz[u]++;
				ans += x[i].w;
			} 
		}
	}
	printf("%d\n", ans);
	return 0;
}
