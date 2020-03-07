#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 3e5 + 10;
const ll kInf = 1e18 + 10;
#define lc (o << 1)
#define rc (o << 1 | 1)

struct Node {
	ll sum, mn, num, secmn, tg;
};
int n, q;
ll a[kN];
Node seg[kN << 2];
void push_down(int o) {
	if(seg[o].tg == kInf) return;
	ll x = seg[o].tg;
	if(seg[lc].mn < x) {
		seg[lc].sum += seg[lc].num * (x - seg[lc].mn);
		seg[lc].mn = seg[lc].tg = x;
	}
	if(seg[rc].mn < x) {
		seg[rc].sum += seg[rc].num * (x - seg[rc].mn);
		seg[rc].mn = seg[rc].tg = x;
	}
	seg[o].tg = kInf;
}
void push_up(int o) {
	seg[o].sum = seg[lc].sum + seg[rc].sum;
	seg[o].mn = min(seg[lc].mn, seg[rc].mn);
	if(seg[lc].mn != seg[rc].mn) {
		if(seg[lc].mn < seg[rc].mn) {
			seg[o].num = seg[lc].num;
			seg[o].secmn = min(seg[lc].secmn, seg[rc].mn);
		}
		else {
			seg[o].num = seg[rc].num;
			seg[o].secmn = min(seg[rc].secmn, seg[lc].mn);
		}
	}
	else {
		seg[o].num = seg[lc].num + seg[rc].num;
		seg[o].secmn = min(seg[lc].secmn, seg[rc].secmn);
	}
}
void build(int l = 1, int r = n, int o = 1) {
	if(l == r) {
		seg[o] = {a[l], a[l], 1, kInf, kInf};
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, lc), build(m + 1, r, rc);
	push_up(o);
}
void update(int ql, int qr, ll x, int l = 1, int r = n, int o = 1) {
	if(l > qr || r < ql || x < seg[o].mn) return;
	if(ql <= l && r <= qr && seg[o].secmn > x) {
		seg[o].sum += seg[o].num * (x - seg[o].mn);
		seg[o].mn = seg[o].tg = x;
		return;
	}
	push_down(o);
	int m = (l + r) >> 1;
	if(ql <= m) update(ql, qr, x, l, m, lc);
	if(qr > m) update(ql, qr, x, m + 1, r, rc);
	push_up(o);
}
ll query(int ql, int qr, int l = 1, int r = n, int o = 1) {
	if(l > qr || r < ql) return 0;
	if(ql <= l && r <= qr) return seg[o].sum;
	push_down(o);
	int m = (l + r) >> 1;
	return query(ql, qr, l, m, lc) + query(ql, qr, m + 1, r, rc);
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	build();
	while(q--) {
		int op, l, r; scanf("%d%d%d", &op, &l, &r);
		if(op == 1) {
			ll x; scanf("%lld", &x);
			update(l, r, x);
		}
		else printf("%lld\n", query(l, r));
	}
	return 0;
}
