#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll kInf = 1e16;
const int kN = 2e5 + 10;
int a[kN], p[kN], pos[kN];
ll pre_sum[kN];
int n;
ll seg[kN << 2], tg[kN << 2];
void push_down(int o) {
	if(tg[o] == 0) return;
	seg[o << 1] += tg[o], tg[o << 1] += tg[o];
	seg[o << 1 | 1] += tg[o], tg[o << 1 | 1] += tg[o];
	tg[o] = 0;
}
void push_up(int o) {seg[o] = min(seg[o << 1], seg[o << 1 | 1]);}
void build(int l = 1, int r = n - 1, int o = 1) {
	if(l == r) {seg[o] = pre_sum[l]; return;}
	int m = (l + r) >> 1;
	build(l, m, o << 1), build(m + 1, r, o << 1 | 1);
	push_up(o);
}
void update(int ql, int qr, int k, int l = 1, int r = n - 1, int o = 1) {
	if(ql > qr) return;
	if(ql <= l && r <= qr) {seg[o] += k, tg[o] += k; return;}
	int m = (l + r) >> 1;
	push_down(o);
	if(ql <= m) update(ql, qr, k, l, m, o << 1);
	if(qr > m) update(ql, qr, k, m + 1, r, o << 1 | 1);
	push_up(o);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", p + i);
		pos[p[i]] = i;
	}
	for(int i = 1; i <= n; i++) scanf("%d", a + i), pre_sum[i] = pre_sum[i - 1] + a[i];
	build();
	ll ans = seg[1];
	//printf("i = 0: %lld\n", ans);
	for(int i = 1; i <= n; i++) {
		int id = pos[i];
		update(1, id - 1, a[id]);
		update(id, n - 1, -a[id]);
		ans = min(ans, seg[1]);
		//printf("i = %d: ans = %lld\n", i, seg[1]);
	}
	printf("%lld\n", ans);
	return 0;
}
