#include <bits/stdc++.h>
using namespace std;
#define int long long
const int kMod = 998244353;
const int kN = 2e5 + 10;
int pw(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = 1LL * res * a % kMod;
		n >>= 1, a = 1LL * a * a % kMod;
	}
	return res;
}
int Inv(int x) {return pw(x, kMod - 2);}
int n, T;
int q[kN];
int pre[kN];

int seg[kN << 2], tg[kN << 2];
void push_down(int o) {
	if(tg[o] == 1) return;
	tg[o << 1] = 1LL * tg[o << 1] * tg[o] % kMod;
	tg[o << 1 | 1] = 1LL * tg[o << 1 | 1] * tg[o] % kMod;
	seg[o << 1] = 1LL * seg[o << 1] * tg[o] % kMod;
	seg[o << 1 | 1] = 1LL * seg[o << 1 | 1] * tg[o] % kMod;
	tg[o] = 1;
}
void push_up(int o) {
	seg[o] = (seg[o << 1] + seg[o << 1 | 1]) % kMod;
}
void build(int l = 1, int r = n, int o = 1) {
	tg[o] = 1;
	if(l == r) {
		seg[o] = pre[l];
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, o << 1), build(m + 1, r, o << 1 | 1);
	push_up(o);
}
void update(int ql, int qr, int k, int l = 1, int r = n, int o = 1) {
	if(ql <= l && r <= qr) {
		seg[o] = 1LL * seg[o] * k % kMod;
		tg[o] = 1LL * tg[o] * k % kMod;
		return;
	}
	push_down(o);
	int m = (l + r) >> 1;
	if(ql <= m) update(ql, qr, k, l, m, o << 1);
	if(qr > m) update(ql, qr, k, m + 1, r, o << 1 | 1);
	push_up(o);
}
int query(int ql, int qr, int l = 1, int r = n, int o = 1) {
	if(ql <= l && r <= qr) {
		return seg[o];
	}
	push_down(o);
	int m = (l + r) >> 1;
	if(qr <= m) return query(ql, qr, l, m, o << 1);
	if(ql > m) return query(ql, qr, m + 1, r, o << 1 | 1);
	return (query(ql, qr, l, m, o << 1) +query(ql, qr, m + 1, r, o << 1 | 1)) % kMod;
}
int32_t main() {
	scanf("%d%d", &n, &T);
	for(int i = n; i >= 1; i--) {
		int x; scanf("%d", &x);
		q[i] = 100LL * Inv(x) % kMod;
	}
	//for(int i = 1; i <= n; i++) printf("%d ", q[i]); puts("");
	int now = 1;
	pre[0] = 1;
	for(int i = 1; i <= n; i++) {
		now = 1LL * now * q[i] % kMod;
		pre[i] = now;
	}
	//for(int i = 1; i <= n; i++) printf("%d ", pre[i]); puts("");
	build();
	//printf("%d\n", seg[1]);
	set<int> s;
	s.insert(0), s.insert(n);
	while(T--) {
		int x;
		scanf("%d", &x);
		x = n + 1 - x;
		//printf("x = %d\n", x);
		if(s.find(x) != s.end()) {
			s.erase(x);				
			auto it = s.lower_bound(x);
			int nxt = *it;
			//printf("remove: nxt = %d\n", nxt);
			it--;
			int prev = *it;
			int k = 1LL * pre[x] * Inv(pre[prev]) % kMod; 
			update(x + 1, nxt, k);
		}
		else {
			auto it = s.lower_bound(x);
			int nxt = *it;
			//printf("insert: nxt = %d\n", nxt);
			it--;
			int prev = *it;
			int k = 1LL * pre[x] * Inv(pre[prev]) % kMod; 
			k = Inv(k);
			update(x + 1, nxt, k);
			s.insert(x);
		}
		//for(int i = 1; i <= n; i++) printf("%d ", query(i, i)); puts("");
		//printf("%d\n", query(1, n));
		printf("%d\n", seg[1]);
	}
	return 0;
}
