#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> g[maxn];
int n;
int in[maxn], out[maxn], dfs_clock;
int dep[maxn], anc[20][maxn];
void dfs(int u, int fa, int d) {
	anc[0][u] = fa;
	in[u] = ++dfs_clock;
	dep[u] = d;
	for(int v : g[u]) if(v != fa) {
		dfs(v, u, d + 1);
	}
	out[u] = dfs_clock;
}
bool ancestor(int x, int y) {return in[x] <= in[y] && out[x] >= out[y];}

#define lc (o << 1)
#define rc (o << 1 | 1)
int seg[maxn << 2], num[maxn << 2], tg[maxn << 2];
void push_up(int o) {
	if(seg[lc] == seg[rc]) seg[o] = seg[lc], num[o] = num[lc] + num[rc];
	else if(seg[lc] < seg[rc]) seg[o] = seg[rc], num[o] = num[rc];
	else seg[o] = seg[lc], num[o] = num[lc];
}
void push_down(int o) {
	if(!tg[o]) return;
	seg[lc] += tg[o], seg[rc] += tg[o];
	tg[lc] += tg[o], tg[rc] += tg[o];
	tg[o] = 0;
}
void build(int l = 1, int r = n, int o = 1) {
	tg[o] = 0;
	if(l == r) {seg[o] = 0, num[o] = 1; return;}
	int m = (l + r) >> 1;
	build(l, m, lc), build(m + 1, r, rc);
	push_up(o);
}
void update(int ql, int qr, int k, int l = 1, int r = n, int o = 1) {
	if(ql > qr || ql > r || qr < l) return;
	//if(o == 1) printf("ql = %d, qr = %d, k = %d\n", ql, qr, k);
	if(ql <= l && r <= qr) {seg[o] += k, tg[o] += k; return;}
	push_down(o);
	int m = (l + r) >> 1;
	if(ql <= m) update(ql, qr, k, l, m, lc);
	if(qr > m) update(ql, qr, k, m + 1, r, rc);
	push_up(o);
}
int climb(int x, int y) {
	int d = dep[y] - dep[x] - 1;
	for(int i = 19; i >= 0; i--) if(d & (1 << i))
		y = anc[i][y];
	return y;
}
int main() {
	int q;
	scanf("%d%d", &n, &q);
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
	}
	dfs(1, 0, 0); out[0] = dfs_clock;
	for(int j = 1; j <= 19; j++)
		for(int i = 1; i <= n; i++) anc[j][i] = anc[j - 1][anc[j - 1][i]];
	set<pair<int, int>> s;
	build();
	while(q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if(x > y) swap(x, y);
		int k;
		if(s.find(make_pair(x, y)) == s.end()) {
			s.insert(make_pair(x, y));
			k = -1;
		}
		else {
			s.erase(make_pair(x, y));
			k = 1;
		}
		if(ancestor(x, y) || ancestor(y, x)) {
			if(ancestor(y, x)) swap(x, y);  
			int z = climb(x, y);			
			update(in[z], in[y] - 1, k);
			update(out[y] + 1, out[z], k);
		}
		else {
			if(in[x] > in[y]) swap(x, y);
			update(1, in[x] - 1, k);
			update(out[x] + 1, in[y] - 1, k);
			update(out[y] + 1, n, k);
		}
//		printf("max = %d, num = %d\n", seg[1], num[1]);
//		printf("ans = ");
		if(seg[1] == 0) printf("%d\n", num[1]);
		else puts("0");
	}
	return 0;
}
