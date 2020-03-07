#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
#define F first
#define S second
const int kN = 1e7 + 10;
const int kB = 1e4;
ll mult(ll x, ll y, ll mod) {
	if(!y) return 0;
	return (mult(x, y / kB, mod) * kB + x * (y % kB)) % mod;
}
ll pw(ll a, ll n, ll mod) {
	ll res = 1;
	while(n) {
		if(n & 1) res = mult(res, a, mod);
		n >>= 1, a = mult(a, a, mod);
	}
	return res;
}
ll pw2(ll a, ll n) {
	ll res = 1;
	while(n) {
		if(n & 1) res = res * a; 
		n >>= 1, a = a * a;
	}
	return res;
}
vector<int> prime; 
bool notp[kN];
void pre() {
	for(int i = 2; i < kN; i++) {
		if(!notp[i]) prime.push_back(i);
		for(int j = 0; j < int(prime.size()) && 1LL * i * prime[j] < kN; j++) {
			notp[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
vector<pii> factorization(ll x) {
	vector<pii> res;
	for(auto p : prime) if(x % p == 0) {
		int cnt = 0;
		while(x % p == 0) x /= p, cnt++;
		res.emplace_back(p, cnt);
	}
	if(x != 1) res.emplace_back(x, 1);
	return res;
}
ll phi(vector<pii> v) {
	ll res = 1;
	for(auto d : v) if(d.S) {
		ll p = d.F; int c = d.S;
		res *= pw2(p, c - 1) * (p - 1);
	}
	return res;
}
ll order(ll x, ll p) {
	ll res = phi(factorization(p));
	vector<pii> v = factorization(res);
	while(true) {
		bool flag = 1;
		for(auto &d : v) if(d.S) {
			if(pw(x, res / d.F, p) == 1) {
				res /= d.F, d.S--;
				flag = 0; break;
			}
		}
		if(flag) return res;
	}
}
ll ans;
ll lcm(vector<ll> v) {
	if(v.empty()) return 1;
	ll res = 1;
	for(auto s : v) {
		res = res / __gcd(res, s) * s;
	}
	return res;
}
void dfs(ll x, ll m, vector<pii> divisor, vector<vector<ll>> ord) {
	if(m == 1) return;
	vector<ll> tmp;	
	for(int i = 0; i < int(divisor.size()); i++) {
		auto d = divisor[i];
		if(!d.S) continue;
		tmp.push_back(ord[i][d.S]);
	}
	//for(ll t : tmp) printf("%lld ", t); puts("");
	ll now = lcm(tmp); 
	//printf("x = %lld, m = %lld, phi = %lld, ord = %lld\n", x, m, phi(divisor), now);
	ans += phi(divisor) / now;
	for(auto &d : divisor) if(d.S) {
		//printf("d.F = %lld, d.S = %d\n", d.F, d.S);
		d.S--, m /= d.F;	
		dfs(x, m, divisor, ord); 
		d.S++, m *= d.F;
	}
}
int main() {
	pre();
	ll m, x;	
	scanf("%lld%lld", &m, &x);
	vector<pii> divisor = factorization(m);
	int num = int(divisor.size());
	vector<vector<ll>> ord(num);
	for(int i = 0; i < num; i++) {
		auto d = divisor[i];
		ll p = d.F;
		ord[i].resize(d.S + 1);
		ord[i][0] = 1;
		ll mod = 1;
		for(int j = 1; j <= d.S; j++) {
			mod *= p;
			//printf("mod = %lld\n", mod);
			ord[i][j] = order(x, mod);
		}
		//printf("p = %lld: ", p);
		//for(int j = 1; j <= d.S; j++) printf("%lld ", ord[i][j]); puts("");
	}
	dfs(x, m, divisor, ord);
	printf("%lld\n", ans + 1);
	return 0;
}
