#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
const ll INF = 1e15;
ll s[maxn];
int n, p[maxn];
ll num[maxn];
ll seg[maxn << 2], tg[maxn << 2];
void push_up(int o) {seg[o] = max(seg[o << 1], seg[o << 1 | 1]);}
void push_down(int o) {
	if(!tg[o]) return;
	seg[o << 1] += tg[o], seg[o << 1 | 1] += tg[o];
	tg[o << 1] += tg[o], tg[o << 1 | 1] += tg[o];
	tg[o] = 0;
}
void build(int l, int r, int o) {
	if(l == r) {seg[o] = num[l]; return;}
	int m = (l + r) >> 1;
	build(l, m, o << 1), build(m + 1, r, o << 1 | 1);
	push_up(o);
}
void update(int l, int r, int o, int ql, int qr, ll k) {
	if(ql <= l && r <= qr) {seg[o] += k, tg[o] +=k; return;}
	push_down(o);
	int m = (l + r) >> 1;
	if(ql <= m) update(l, m, o << 1, ql, qr, k);
	if(qr > m) update(m + 1, r, o << 1 | 1 ,ql ,qr, k);
	push_up(o);
}
typedef pair<int, int> pii;
int query(int l, int r, int o, ll k) {
	if(l == r) return l;
	push_down(o);
	int m = (l + r) >> 1;
//	printf("l = %d, r = %d, seg[o << 1] = %lld, seg[o << 1 | 1] = %lld\n", l, r, seg[o << 1], seg[o << 1 | 1]);
	if(k <= seg[o << 1]) return query(l, m, o << 1, k);
	else return query(m + 1, r, o << 1 | 1, k);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &s[i]);
	for(int i = 2; i <= n; i++) num[i] = num[i - 1] + (i - 1);
	build(1, n, 1);
	for(int i = n; i >= 1; i--) {
		int k = query(1, n, 1, s[i]);
		p[i] = k;
		if(k < n) update(1, n, 1, k + 1, n, -k);
		update(1, n, 1, k, k, -INF);
	}
	for(int i = 1; i <= n; i++) printf("%d ", p[i]);
	puts("");
	return 0;
}
