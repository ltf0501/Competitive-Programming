#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long ll;
vector<int> p;
vector<ll> pp[maxn];
bool notp[maxn];
void pre() {
	for(int i = 2; i < maxn; i++) {
		if(!notp[i]) p.push_back(i);
		for(int j = 0; j < (int)p.size() && 1LL * i * p[j] < maxn; j++) {
			notp[i * p[j]] = 1;
			if(i % p[j] == 0) break;
		}
	}
	//for(int i = 0; i < 30; i++) printf("%d ", p[i]);
}
bool check(ll x) {
	for(int i = 0; i < (int)p.size() && 1LL * p[i] * p[i] <= x; i++) 
		if(x % p[i] == 0) return 0;
	return 1;
}
ll ans;
void dfs(ll n, int dep) {
	if(n == 1) {ans++; return ;}
	if(dep >= (int)p.size() || 1LL * p[dep] * p[dep] + 1 > n) {
		if(check(n - 1) && n - 1 >= p[dep]) ans++;
		return;
	}
	dfs(n, dep + 1);
	ll cur = p[dep];
	while(cur + 1 <= n) {
		if(n % (cur + 1) == 0) dfs(n / (cur + 1), dep + 1);
		cur *= p[dep];
	}
}
int main() {
	pre();
	ll A;
	scanf("%lld", &A);
	dfs(A, 0);
	printf("%lld\n", ans);
	return 0;
}
