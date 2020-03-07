#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int INF = 2e9 + 1000;
typedef long long ll;
#define lc (o << 1)
#define rc (o << 1 | 1)
int a[maxn];
struct P {
	ll ans;
	array<ll, 10> mi;
} seg[maxn << 2];
int pw[15];
int n, q;
bool is(int x, int id) {
	return (x / pw[id]) % 10;
}
void push_up(int o) {
	seg[o].ans = min(seg[lc].ans, seg[rc].ans);
	for(int i = 0; i < 10; i++) {
		if(seg[lc].mi[i] < INF && seg[rc].mi[i] < INF) seg[o].ans = min(seg[o].ans, seg[lc].mi[i] + seg[rc].mi[i]);
		seg[o].mi[i] = min(seg[lc].mi[i], seg[rc].mi[i]);
	}
}
void build(int l = 1, int r = n, int o = 1) {
	if(l == r) {
		seg[o].ans = INF;
		for(int i = 0; i < 10; i++) seg[o].mi[i] = is(a[l], i) ? a[l] : INF;
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, lc), build(m + 1, r, rc);
	push_up(o);
}
void update(int pos, int k, int l = 1, int r = n, int o = 1) {
	if(l == r) {
		seg[o].ans = INF;
		for(int i = 0; i < 10; i++) seg[o].mi[i] = is(k, i) ? k : INF;
		return;
	}
	int m = (l + r) >> 1;
	if(pos <= m) update(pos, k, l, m, lc);
	else update(pos, k, m + 1, r, rc);
	push_up(o);
}
P query(int ql, int qr, int l = 1, int r = n, int o = 1) {
	if(ql <= l && r <= qr) return seg[o];
	int m = (l + r) >> 1;
	if(qr <= m) return query(ql, qr, l, m, lc);
	if(ql > m) return query(ql, qr, m + 1, r, rc);
	P le = query(ql, qr, l, m, lc);
	P ri = query(ql, qr, m + 1, r, rc);
	array<ll, 10> tmp;
	for(int i = 0; i < 10; i++) tmp[i] = min(le.mi[i], ri.mi[i]);
	ll res = min(le.ans, ri.ans);
	for(int i = 0; i < 10; i++) {
		if(le.mi[i] < INF && ri.mi[i] < INF) res = min(res, le.mi[i] + ri.mi[i]);
	}
	return (P){res, tmp};
}
int main() {
	pw[0] = 1;
	for(int i = 1; i < 10; i++) pw[i] = pw[i - 1] * 10;
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build();
	while(q--) {
		int op, l, r;
		scanf("%d%d%d", &op, &l, &r);
		if(op == 1) {
			update(l, r), a[l] = r;
		}
		else {
			P res = query(l, r);
			if(res.ans == INF) puts("-1");
			else printf("%lld\n", res.ans);
		}
	}
	return 0;
}
