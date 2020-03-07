#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 3e5 + 10;
typedef pair<int, int> pii;
#define F first
#define S second
pii a[maxn];
void add(int& a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
void sub(int& a, int b) {
	a -= b;
	if(a < 0) a += mod;
}
int fac[maxn];
void pre() {
	fac[0] = 1;
	for(int i = 1; i < maxn; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
}
int main() {
	pre();
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].F, &a[i].S);
	sort(a + 1, a + n + 1, [](pii x, pii y) {return x.S < y.S;});
	int ans = fac[n], tot = 1;
	for(int i = 1, cnt = 0; i <= n; i++) {
		cnt++;
		if(i == n || a[i].S != a[i + 1].S) {
			tot = 1LL * tot * fac[cnt] % mod;
			cnt = 0;
		}
	}
//	printf("tot = %d\n", tot);
	sub(ans, tot);
	sort(a + 1, a + n + 1);
	tot = 1;
	int num = 1;
	bool flag = 1;
	vector<int> v;
	for(int i = 1, cnt = 0; i <= n; i++) {
		cnt++;
		v.push_back(a[i].S);
		if(i == n || a[i].F != a[i + 1].F) {
			tot = 1LL * tot * fac[cnt] % mod;
			cnt = 0;
			for(int j = 0, tmp_cnt = 0; j < (int)v.size(); j++) {
				tmp_cnt++;
				if(j == (int)v.size() - 1 || v[j] != v[j + 1]) {
					num = 1ll * num * fac[tmp_cnt] % mod;
					tmp_cnt = 0;
				}
			}
			if(i < n && a[i].S > a[i + 1].S) flag = 0;
			v.clear();
		}
	}
//	printf("tot = %d\n", tot);
	sub(ans, tot);
	if(flag) add(ans, num);
	printf("%d\n", ans);
	return 0;
}
