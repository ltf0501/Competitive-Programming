#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
const int kMod = 1e9 + 7;
const int kP = 890501;
#define ALL(v) v.begin(), v.end()
int n, m;
char c[kN];
int pre[2][kN];
vector<int> zero;
vector<int> v;
int p[kN], h[2][kN];
int calc(int l, int r, int c) {
	return pre[c][r] - (l ? pre[c][l - 1] : 0);
}
void build() {
	p[0] = 1;
	for(int i = 1; i < kN; i++) p[i] = 1LL * p[i - 1] * kP % kMod;
	m = int(v.size());
	if(!v.empty()) h[0][0] = v[0], h[1][0] = !v[0];
	for(int i = 1; i < m; i++) {
		h[0][i] = (1LL * h[0][i - 1] * kP % kMod + v[i]) % kMod;
		h[1][i] = (1LL * h[1][i - 1] * kP % kMod + !v[i]) % kMod;
	}
}
int Hash(int l, int r, int c) {
	if(l > r) return 0;
	if(!l) return h[c][r];
	return ((h[c][r] - 1LL * h[c][l - 1] * p[r - l + 1] % kMod) % kMod + kMod) % kMod;
}
int main() {
	scanf("%d", &n);
	scanf("%s", c);
	for(int i = 0; i < n; i++) {
		if(i) pre[0][i] = pre[0][i - 1], pre[1][i] = pre[1][i - 1];
		
		if(c[i] == '0') {
			zero.push_back(i);
			pre[i & 1][i]++;
			v.push_back(i & 1);
		}
	}
	build();

	int q; scanf("%d", &q);
	while(q--) {
		int x, y, len; scanf("%d%d%d", &x, &y, &len);
		x--, y--;
		bool flag = ((x + y) & 1);
		if(calc(x, x + len - 1, 0) != calc(y, y + len - 1, flag) ||
				calc(x, x + len - 1, 1) != calc(y, y + len - 1, flag ^ 1)) {
			puts("NO"); continue;
		}
		int l1 = lower_bound(ALL(zero), x) - zero.begin(), l2 = lower_bound(ALL(zero), y) - zero.begin();

		int r1 = lower_bound(ALL(zero), x + len) - zero.begin(), r2 = lower_bound(ALL(zero), y + len) - zero.begin();
		r1--, r2--;
		if(r1 - l1 != r2 - l2 || Hash(l1, r1, x & 1) != Hash(l2, r2, y & 1)) puts("NO");
		else puts("YES");
	}
	return 0;
}
