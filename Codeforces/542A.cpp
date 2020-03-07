#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
#define lc (o << 1)
#define rc (o << 1 | 1)
#define ALL(v) v.begin(), v.end()
#define F first
#define S second
struct P {
	int l, r, c;
}a[maxn], b[maxn];
int n, m, N;
vector<int> vv;
struct Q {
	int x, flag, type, id;
	bool operator < (const Q& c) const {
		if(x != c.x) return x < c.x;
		return type < c.type;
	}
};
vector<Q> v;
pair<int, int> seg[maxn << 4], tr[maxn << 4];
void push_up(int o) {
	seg[o] = max(seg[lc], seg[rc]);
}
void build(int l = 1, int r = N, int o = 1) {
	if(l == r) {tr[l] = seg[o] = make_pair(0, -1); return;}
	int m = (l + r) >> 1;
	build(l, m, lc), build(m + 1, r, rc);
	push_up(o);
}
void update(int x, pair<int, int> p, int l = 1, int r = N, int o = 1) {
	if(l == r) {seg[o] = max(p, tr[l]); return;}
	int m = (l + r) >> 1;
	if(x <= m) update(x, p, l, m, lc);
	else update(x, p, m + 1, r, rc);
	push_up(o);
}
pair<int, int> query(int ql, int qr, int l = 1, int r = N, int o = 1) {// find max
	if(ql <= l && r <= qr) return seg[o];
	int m = (l + r) >> 1;
	if(qr <= m) return query(ql, qr, l, m, lc);
	if(ql > m) return query(ql, qr, m + 1, r, rc);
	return max(query(ql, qr, l, m, lc), query(ql, qr, m + 1, r, rc));
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		vv.push_back(l), vv.push_back(r);
		a[i] = {l, r, -1};
	}
	for(int i = 1; i <= m; i++) {
		int l, r, c;
		scanf("%d%d%d", &l, &r, &c);
		vv.push_back(l), vv.push_back(r);
		b[i] = {l, r, c};
	}

	sort(vv.begin(), vv.end());
	N = unique(ALL(vv)) - vv.begin();
	vv.resize(N);
//	printf("vv: "); for(int x : vv) printf("%d ", x); puts("");
	for(int i = 1; i <= n; i++) {
		a[i].l = lower_bound(ALL(vv), a[i].l) - vv.begin() + 1;
		a[i].r = lower_bound(ALL(vv), a[i].r) - vv.begin() + 1;
		v.push_back({a[i].l, 1, 0, i});
		v.push_back({a[i].r, -1, 0, i});
	}
	for(int i = 1; i <= m; i++) {
		b[i].l = lower_bound(ALL(vv), b[i].l) - vv.begin() + 1;
		b[i].r = lower_bound(ALL(vv), b[i].r) - vv.begin() + 1;
		v.push_back({b[i].l, 1, 1, i});
		v.push_back({b[i].r, -1, 1, i});
	}
	sort(ALL(v));	
	ll ans = 0;
	pair<int, int> p = make_pair(-1, -1);

	build();
	for(auto s : v) {
		if(s.flag == 1) continue;
		if(s.type == 0) update(a[s.id].l, make_pair(vv[a[s.id].r - 1] - vv[a[s.id].l - 1], s.id)), tr[a[s.id].l] = max(tr[a[s.id].l], make_pair(vv[a[s.id].r - 1] - vv[a[s.id].l - 1], s.id));
		else {
			pair<int, int> tmp = query(b[s.id].l, b[s.id].r);
			ll now = 1LL * tmp.F * b[s.id].c;
			if(ans < now) ans = now, p = make_pair(tmp.second, s.id);
		}
	}
	
	build();	
	for(auto s : v) {
		if(s.flag == -1) continue;
		if(s.type == 0) update(s.x, make_pair(a[s.id].r, s.id)), tr[s.x] = max(tr[s.x], make_pair(a[s.id].r, s.id));
		else {
			pair<int, int> tmp = query(1, s.x);
			ll now = 1LL * (vv[b[s.id].r - 1] - vv[b[s.id].l - 1]) * b[s.id].c;
			if(tmp.F >= b[s.id].r && ans < now) ans = now, p = make_pair(tmp.S, s.id);
		}
	}

	build();
	for(auto s : v) {
		if(s.flag == 1) continue;
		if(s.type == 0) update(a[s.id].l, make_pair(vv[a[s.id].r - 1], s.id)), tr[a[s.id].l] = max(tr[a[s.id].l], make_pair(vv[a[s.id].r - 1], s.id));
		else {
			pair<int, int> tmp = query(1, b[s.id].l);
			ll now = 1LL * (tmp.F - vv[b[s.id].l - 1]) * b[s.id].c;
			if(ans < now) ans = now, p = make_pair(tmp.S, s.id);
		}
	}

	const int INF = 2e9;
	build();
	for(int i = (int)v.size() - 1; i >= 0; i--) {
		auto s = v[i];
		if(s.flag == -1) continue;
		if(s.type == 0) update(a[s.id].r, make_pair(INF - vv[a[s.id].l - 1], s.id)), tr[a[s.id].r] = max(tr[a[s.id].r], make_pair(INF - vv[a[s.id].l - 1], s.id));
		else {
			pair<int, int> tmp = query(b[s.id].r, N);
			ll now = 1LL * (tmp.F - (INF - vv[b[s.id].r - 1])) * b[s.id].c;
			if(ans < now) ans = now, p = make_pair(tmp.S, s.id);
		}
	}
	printf("%lld\n", ans);
	if(p != make_pair(-1, -1)) printf("%d %d\n", p.F, p.S);
	return 0;
}
