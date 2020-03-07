#include <bits/stdc++.h>
using namespace std;
const int kN = 1e6 + 1;
const int kInf = 1e9;
int n, q;
int a[kN];
bool times[kN + 10];
int pre[kN + 10];
struct P {
	int mn, cnt, tg;
} seg[kN << 2];
P mrge(const P &a, const P &b) {
	P res = {min(a.mn, b.mn), 0, 0};
	if(res.mn == a.mn) res.cnt += a.cnt;
	if(res.mn == b.mn) res.cnt += b.cnt;
	return res;
}
void push_up(int o) {seg[o] = mrge(seg[o << 1], seg[o << 1 | 1]);}
void push_down(int o) {
	if(!seg[o].tg) return;
	seg[o << 1].mn += seg[o].tg, seg[o << 1].tg += seg[o].tg;
	seg[o << 1 | 1].mn += seg[o].tg, seg[o << 1 | 1].tg += seg[o].tg;
	seg[o].tg = 0;
}
void build(int l = 0, int r = kN - 1, int o = 1) {
	if(l == r) {
		seg[o] = {pre[l], 1, 0};
		if(!times[l]) seg[o].mn += kInf;
		//else printf("pre[%d] = %d\n", l, pre[l]);
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, o << 1), build(m + 1, r, o << 1 | 1);
	push_up(o);
}
void update(int ql, int qr, int val, int l = 0, int r = kN - 1, int o = 1) {
	if(ql > qr) return;
	if(ql <= l && r <= qr) {
		seg[o].mn += val, seg[o].tg += val;
		return;
	}
	push_down(o);
	int m = (l + r) >> 1;
	if(ql <= m) update(ql, qr, val, l, m, o << 1);
	if(qr > m) update(ql, qr, val, m + 1, r, o << 1 | 1);
	push_up(o);
}
bool type;
void pattern(int i, int val) {
	int t[2] = {a[i], a[i + 1]};	
	if(t[0] > t[1]) swap(t[0], t[1]);
	if(type) update(t[0], t[1] - 1, val);
	else pre[t[0]] += val, pre[t[1]] -= val;
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), times[a[i]] = 1;
	times[0] = 1;
	a[0] = kN, times[a[0]] = 1;
	for(int i = 0; i <= n; i++) pattern(i, 1);
	for(int i = 1; i < kN; i++) pre[i] += pre[i - 1];
	build();
	type = 1;
	while(q--) {
		int id, val;
		scanf("%d%d", &id, &val);
		pattern(id - 1, -1), pattern(id, -1);
		update(a[id], a[id], kInf), times[a[id]] = 0;
		a[id] = val;
		update(a[id], a[id], -kInf), times[a[id]] = 1;
		pattern(id - 1, 1), pattern(id, 1);
		printf("%d\n", seg[1].cnt - 1);
	}
	return 0;
}
