#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;
typedef pair<int, int> pii;
#define F first
#define S second
vector<int> p;
int f[maxn];
int inv[40];
void add(int &x, int y) {
	x += y;
	if(x > mod) x -= mod;
}
int mul(int x, int y) {
	return 1LL * x * y % mod;
}
int pw(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = mul(res, a);
		n >>= 1, a = mul(a, a);
	}
	return res;
}
int INV(int a) {return pw(a, mod - 2);}
void pre() {
	f[1] = 1;
	for(int i = 2; i < maxn; i++) {
		if(!f[i]) p.push_back(i), f[i] = i;
		for(int j = 0; j < int(p.size()) && 1LL * i * p[j] < maxn; j++) {
			f[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
//	for(int i = 2; i < 50; i++) 
//		printf("f[%d] = %d\n", i, f[i]);
	inv[0] = inv[1] = 1;
	for(int i = 2; i < 40; i++) inv[i] = mul(inv[i - 1], INV(i));
}
int C(int x, int y) {
	if(x < y || x < 0 || y < 0) return 0;
	if(y > x - y) y = x - y;
	int res = 1;
	for(int i = 0; i < y; i++) res = mul(res, x - i);
	assert(y < 40);
	res = mul(res, inv[y]);
	//printf("x = %d, y = %d: %d\n", x, y, res);
	return res;
}
int main() {
	pre();
	int n, k;
	scanf("%d%d", &n, &k);
	k--;
	int tot = 0;
	for(int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a); 
		if(k == -1) {
			add(tot, a);
			continue;
		}
		int ans = 1;
		while(a != 1) {
			int x = f[a];
			int m = 0;
			while(a % x == 0)
				m++, a /= x;
			int xx = 1;
			//printf("x = %d, m = %d\n", x, m);
			int tmp = 0;
			for(int i = 0; i <= m; i++) {
				add(tmp, mul(xx, C(k + m - i, k))); 
				xx = mul(xx, x);
			}
			ans = mul(ans, tmp);
		}
		add(tot, ans);
	}
	printf("%d\n", tot);
	return 0;
}
