#include <bits/stdc++.h>
using namespace std;
#define lc (o << 1)
#define rc (o << 1 | 1)
typedef long long ll;
const int kN = 1.5e5 + 10;
const int kInf = 1e9 + 10;

int n;
int a[kN], pos[kN];
int nxt[kN];
ll ans[kN];
struct Magic {
	int nxt[kN];	
	struct Bit {
		int bit[kN];
		void init() {
			for(int i = 1; i <= n; i++) bit[i] = 0;
		};
		void add(int x, int d) {
			for(int i = x; i <= n; i += i & -i) bit[i] += d;
		}
		ll query(int x) {
			ll res = 0;
			for(int i = x; i; i -= i & -i) res += bit[i];
			return res;
		}
	};
	Bit b, b2;

	struct Node {
		ll sum;
		int mx, num;
		int secmx;
		int tg;
	};
	Node seg[kN << 2];
	void init(int *a) {
		for(int i = 1; i <= n; i++) nxt[i] = a[i];
		b.init(), b2.init();
	}
	void push_down(int l, int r, int o) {
		if(seg[o].tg == -kInf) return;
		int x = seg[o].tg;
		if(seg[lc].mx < x) {
			seg[lc].sum += 1LL * seg[lc].num * (b.query(x) - b.query(seg[lc].mx));
			seg[lc].mx = x;
			seg[lc].tg = x;
		}
		if(seg[rc].mx < x) {
			seg[rc].sum += 1LL * seg[rc].num * (b.query(x) - b.query(seg[rc].mx));
			seg[rc].mx = x;
			seg[rc].tg = x;
		}
		seg[o].tg = -kInf;
	}
	void push_up(int o) {
		seg[o].sum = seg[lc].sum + seg[rc].sum;
		seg[o].mx = max(seg[lc].mx, seg[rc].mx);
		if(seg[lc].mx != seg[rc].mx) {
			if(seg[lc].mx > seg[rc].mx) {
				seg[o].num = seg[lc].num;
				seg[o].secmx = max(seg[lc].secmx, seg[rc].mx);
			}
			else {
				seg[o].num = seg[rc].num;
				seg[o].secmx = max(seg[rc].secmx, seg[lc].mx);
			}
		}
		else {
			seg[o].num = seg[lc].num + seg[rc].num;
			seg[o].secmx = max(seg[lc].secmx, seg[rc].secmx);
		}
	}
	void build(int l = 1, int r = n, int o = 1) {
		if(l == r) {
			seg[o] = {0, nxt[l], 1, -kInf, -kInf};
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, lc), build(m + 1, r, rc);
		push_up(o);
	}
	void set(int pos, int x, int l = 1, int r = n, int o = 1) {
		if(l == r) {
			seg[o] = {b.query(x), x, 1, -kInf, -kInf};
			printf("XD = %lld\n", b.query(x));
			return;
		}
		push_down(l, r, o);
		int m = (l + r) >> 1;
		if(pos <= m) set(pos, x, l, m, lc);
		else set(pos, x, m + 1, r, rc);
		push_up(o);
	}
	void update(int ql, int qr, int x, int l = 1, int r = n, int o = 1) {
		if(l > qr || r < ql || seg[o].mx <= x) return;
		if(ql <= l && r <= qr && seg[o].secmx < x) {
			seg[o].tg = x;
			ll k;
			seg[o].sum += 1LL * seg[o].num * (k = b.query(x) - b.query(seg[o].mx));
			printf("k = %lld, x = %d, seg[o].mx = %d\n", k, x, seg[o].mx);
			seg[o].mx = x;
			return;
		}
		push_down(l, r, o);
		int m = (l + r) >> 1;
		if(ql <= m) update(ql, qr, x, l, m, lc);
		if(qr > m) update(ql, qr, x, m + 1, r, rc);
		push_up(o);
	}
	void add(int x) {
		b2.add(x, 1);
		int t;
		b.add(x, t = b2.query(x));
	}
	ll query_sum(int x) {
		return b2.query(x);
	}
};
Magic solver;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i), pos[a[i]] = i;

	for(int i = 1; i <= n; i++) nxt[i] = 0;
	//for(int i = 1; i <= n; i++) ans[i] = i;
	solver.init(nxt);
	solver.build();
	for(int i = 1; i <= n; i++) {
		int x = pos[i];
		solver.update(1, x - 1, x - 1); 
		ans[i] += solver.seg[1].sum - 1LL * i * (i - 1) / 2;
		printf("sum = %lld\n", solver.seg[1].sum);
		ans[i] += solver.query_sum(n) - solver.query_sum(x);
		solver.add(x);
		solver.set(x, n);
	}
	/*
	solver.init(nxt);
	for(int i = 1; i <= n; i++) pos[a[i]] = n + 1 - i;
	for(int i = 1; i <= n; i++) {
		int x = pos[i];
		solver.update(1, x - 1, x - 1);
		solver.set(x, x, n);
		ans[i] += solver.seg[1].sum - 1LL * i * (i + 1) / 2;
		ans[i] += solver.query_sum(n) - solver.query_sum(x);
		solver.add(x);
	}
	*/
	for(int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
	return 0;
}
