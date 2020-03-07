#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define F first
#define S second
#define lc (o << 1)
#define rc (o << 1 | 1)
const int kN = 2e5 + 10;
const ll kInf = 1e18 + 10;

int n, q;
ll a[kN], b[kN];
vector<int> g[kN];
int in[kN], out[kN], dfs_clock;
pll p1[kN], p2[kN];
void dfs(int u) {
	in[u] = ++dfs_clock;
	for(int v : g[u]) {
		a[v] += a[u], b[v] += b[u];
		dfs(v);
	}
	out[u] = dfs_clock;
}
struct SegmentTree {
	pll pos[kN << 2];
	struct Node {
		ll a, b;
		ll wait, tg;
	};
	Node seg[kN << 2];
	void init(pll *a) {
		for(int i = 1; i <= n; i++) pos[i] = a[i];
	}
	void push_down(int o) {
		if(seg[o].tg == 0) return;
		seg[lc].tg += seg[o].tg, seg[rc].tg += seg[o].tg;
		seg[lc].wait -= seg[o].tg, seg[rc].wait -= seg[o].tg;
		seg[lc].a += seg[o].tg, seg[rc].a += seg[o].tg;
		seg[o].tg = 0; 
	}
	void push_up(int o) {
		ll a1 = seg[lc].a, b1 = seg[lc].b;
		ll a2 = seg[rc].a, b2 = seg[rc].b;
		if(a1 * b1 > a2 * b2) seg[o].a = a1, seg[o].b = b1;
		else seg[o].a = a2, seg[o].b = b2;
		seg[o].wait = min(seg[lc].wait, seg[rc].wait);
		if(b1 != b2) {
			ll tmp = (a2 * b2 - a1 * b1) / (b1 - b2);
			if(tmp >= 0) seg[o].wait = min(seg[o].wait, tmp);
		}
	}
	void build(int l = 1, int r = n, int o = 1) {
		if(l == r) {
			seg[o] = {pos[l].F, pos[l].S, kInf, 0};
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, lc), build(m + 1, r, rc);
		push_up(o);
	}
	void update(int ql, int qr, int x, int l = 1, int r = n, int o = 1) {
		if(ql > r || qr < l) return;
		if(ql <= l && r <= qr && seg[o].wait >= x) {
			seg[o].tg += x, seg[o].wait -= x, seg[o].a += x;
			return;
		}
		push_down(o);
		int m = (l + r) >> 1;
		if(ql <= m) update(ql, qr, x, l, m, lc);
		if(qr > m) update(ql, qr, x, m + 1, r, rc);
		push_up(o);
	}
	ll query(int ql, int qr, int l = 1, int r = n, int o = 1) {
		if(ql > r || qr < l) return -kInf;
		if(ql <= l && r <= qr) return seg[o].a * seg[o].b;
		push_down(o);
		int m = (l + r) >> 1;
		return max(query(ql, qr, l, m, lc), query(ql, qr, m + 1, r, rc));
	}
};
SegmentTree t1, t2;
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 2, x; i <= n; i++) {
		scanf("%d", &x);
		g[x].push_back(i);
	}
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	for(int i = 1; i <= n; i++) scanf("%lld", b + i);
	dfs(1);
	for(int i = 1; i <= n; i++) {
		p1[in[i]] = {a[i], b[i]}, p2[in[i]] = {a[i], -b[i]};
	}
	t1.init(p1), t2.init(p2);
	t1.build(), t2.build();
	while(q--) {
		int op, v; scanf("%d%d", &op, &v);
		if(op == 1) {
			int x; scanf("%d", &x);
			t1.update(in[v], out[v], x);
			t2.update(in[v], out[v], x);
		}
		else {
			printf("%lld\n", max(t1.query(in[v], out[v]), t2.query(in[v], out[v])));
		}
	}
	return 0;
}
