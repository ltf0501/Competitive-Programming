#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int INF = (int)1e9;
deque<int> v[maxn];
int n;
int a[maxn], b[maxn];
int seg[maxn << 2];
void push_up(int o) {
	seg[o] = min(seg[o << 1], seg[o << 1 | 1]);
}
void build(int l, int r, int o) {
	if(l == r) {
		seg[o] = a[l];
		return;
	}
	int m = (l + r) >> 1;
	build(l, m, o << 1), build(m + 1, r, o << 1 | 1);
	push_up(o);
}
void update(int l, int r, int o, int x, int k) {
	if(l == r) {
		seg[o] = k;
		return;
	}
	int m = (l + r) >> 1;
	if(x <= m) update(l, m, o << 1, x, k);
	else update(m + 1, r, o << 1 | 1, x, k);
	push_up(o);
}
int query(int l, int r, int o, int ql, int qr) {
	if(ql <= l && r <= qr) return seg[o];
	int m = (l + r) >> 1;
	if(qr <= m) return query(l, m, o << 1, ql, qr);
	if(ql > m) return query(m + 1, r, o << 1 | 1, ql, qr);
	return min(query(l, m, o << 1, ql, qr), query(m + 1, r, o << 1 | 1, ql, qr));
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)v[i].clear();
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for(int i = 1; i <= n; i++) v[a[i]].push_back(i);
		bool flag = 1;
		build(1, n, 1);
		for(int i = 1; i <= n; i++) {
			if(v[b[i]].empty()) {
				flag = 0;
				break;
			}
			int id = v[b[i]].front(); v[b[i]].pop_front();
			if(id > 1 && query(1, n, 1, 1, id - 1) < b[i]) {
				flag = 0;
				break;
			}
			update(1, n, 1, id, INF);
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
