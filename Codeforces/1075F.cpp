#include <bits/stdc++.h>
using namespace std;
map<int, int> p, sz, path;
int find(int x) {
	if(p.find(x) == p.end()) {p[x] = x, sz[x] = 1, path[x] = 0;}
	if(p[x] == x) return x;
	int fa = p[x];
	p[x] = find(fa);
	path[x] ^= path[fa];
	return p[x];
} 
void Union(int x, int y, int k) {
	int a = find(x), b = find(y);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	p[b] = a, sz[a] += sz[b];
	path[b] = k ^ path[x] ^ path[y];
}
int ans;
void ch(int& x) {
	if(ans == -1) x ^= 1;
	else x ^= ans;
}
int main() {
	int q;
	scanf("%d", &q);
	while(q--) {
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		ch(l), ch(r); 
		if(l > r) swap(l, r);
		//printf("l = %d, r = %d\n", l, r);
		r++;
		if(op == 1) {
			int x;
			scanf("%d", &x);
			ch(x);
			//printf("x = %d\n", x);
			Union(l, r, x);
			//printf("path[l] = %d, path[r] = %d, p[l] = %d, p[r] = %d\n", path[l], path[r], p[l], p[r]);
		}
		else {
	//		printf("p[l] = %d, p[r] = %d, sz[l] = %d, sz[r] = %d\n", p[l], p[r], sz[l], sz[r]);
	//		printf("find(l) = %d, find(r) = %d\n", find(l), find(r));
			if(find(l) != find(r)) ans = -1;
			else ans = path[l] ^ path[r]; //printf("path[l] = %d, path[r] = %d, p[l] = %d, p[r] = %d\n", path[l], path[r], p[l], p[r]); 
			printf("%d\n", ans);
		}
	}
	return 0;
}
