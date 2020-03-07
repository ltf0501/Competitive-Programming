#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int maxc = 1e6 + 10;
const int mod = 998244353;

int num[maxc];
int cal[maxc];

vector<int> p;
int low[maxc], f[maxc];
int pw(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = 1LL * res * a % mod;
		a = 1LL * a * a % mod, n >>= 1;
	}
	return res;
}
int INV(int a) {return pw(a, mod - 2);}
void pre() {
	f[1] = 1;
	for(int i = 2; i < maxc; i++) {
		if(!f[i]) {
			p.push_back(i);
			low[i] = i;
			int _p = INV(i);
			f[i] =  1LL * (mod - i + 1) * _p % mod;//-(p - 1) / p
		}
		for(int j = 0; j < int(p.size()) && 1LL * i * p[j] < maxc; j++) {
			if(i % p[j] == 0) {
				low[i * p[j]] = low[i] * p[j];
				if(low[i] == i) {
					f[i * p[j]] = 1LL * (mod - p[j] + 1) * INV(i * p[j]) % mod; // -(p - 1) / p^k
				}
				else {
					f[i * p[j]] = 1LL * f[i / low[i]] * f[p[j] * low[i]] % mod;
				}
				break;
			}
			f[i * p[j]] = 1LL * f[i] * f[p[j]] % mod;
			low[i * p[j]] = p[j];
		}
	}
//	for(int i = 1; i <= 30; i++) 
//		printf("f[%d] = %d\n", i, f[i]);
}
void add(int& a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
void sub(int& a, int b) {
	a -= b;
	if(a < 0) a += mod;
}
int main() {
	pre();
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		num[x]++;
	}
	for(int i = 1; i < maxc; i++) {
		int a = 0, b = 0;
		for(int j =	i; j < maxc; j += i) {
			add(a, 1LL * j * num[j] % mod);
			add(b, 1LL * j * j % mod * num[j] % mod);
		}
		a = 1LL * a * a % mod;
		sub(a, b);
		cal[i] = a;
	}
	int ans = 0;
	for(int i = 1; i < maxc; i++) {
		add(ans, 1LL * cal[i] * f[i] % mod);
	}
	ans = 1LL * ans * INV(2) % mod;
	printf("%d\n", ans);
	return 0;
}
