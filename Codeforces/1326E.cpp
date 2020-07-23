#include <bits/stdc++.h>
using namespace std;
const int kN = 3e5 + 10;
typedef pair<int, int> pii;
#define F first
#define S second

int n;
pii p[kN];
int q[kN];

int seg[kN << 2], tg[kN << 2];
void push_down(int o) {
	if(!tg[o]) return;
	seg[o << 1] += tg[o], seg[o << 1 | 1] += tg[o];
	tg[o << 1] += tg[o], tg[o << 1 | 1] += tg[o];
	tg[o] = 0;
}
void push_up(int o) {
	seg[o] = max(seg[o << 1], seg[o << 1 | 1]);
}
void update(int ql, int qr, int d, int l = 1, int r = n, int o = 1) {
	if(ql <= l && r <= qr) {
		seg[o] += d, tg[o] += d;
		return;
	}
	int m = (l + r) >> 1;
	push_down(o);
	if(ql <= m) update(ql, qr, d, l, m, o << 1);
	if(qr > m) update(ql, qr, d, m + 1, r, o << 1 | 1);
	push_up(o);
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &p[i].F), p[i].S = i;
	for(int i = 1; i <= n; i++) scanf("%d", &q[i]);
	sort(p + 1, p + n + 1);

	int ans = n + 1;

	for(int i = 0; i < n; i++) {
		while(seg[1] <= 0) {
			ans--;
			update(1, p[ans].S, 1);
		}
		printf("%d ", ans);
		update(1, q[i + 1], -1);
	}
	puts("");

	return 0;
}
