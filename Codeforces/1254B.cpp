#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
const ll INF = 1e16;
const int maxn = 1e6 + 10;
int a[maxn];
int n;
vector<int> p;
bool notp[maxn];
void pre() {
	for(int i = 2; i < maxn; i++) {
		if(!notp[i]) p.push_back(i);
		for(int j = 0; j < int(p.size()) && 1LL * i * p[j] < maxn; j++) {
			notp[i * p[j]] = 1;
			if(i % p[j] == 0) break;
		}
	}
}
int main() {
	pre();
	scanf("%d", &n);
	ll sum = 0;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
	if(sum == 1) return puts("-1"), 0;	
	int g = 0;
	for(int i = 0; i < n; i++) g = __gcd(g, a[i]);
	if(g > 1) return puts("0"), 0;
	ll ans = -1;
	for(int pp : p) if(sum % pp == 0) {
		//printf("pp = %d\n", pp);
		vector<pii> v;
		ll now = 0;
		ll tmp = 0;
		for(int i = 0; i < n; i++) {
			int b = a[i] % pp;
			if(now + b < pp) {
				v.push_back({b, i});
				now += b;
				continue;
			}
			v.push_back({pp - now, i});
			int sz = int(v.size());
			int id = -1;
			ll tot = 0;
			//printf("v:\n");
			//for(pii s : v) printf("%d %d\n", s.F, s.S);
			for(int j = 0; j < sz; j++) {
				if(tot < (pp + 1) / 2 && tot + v[j].F >= (pp + 1) / 2) {
					id = v[j].S;
					break;
				}
				tot += v[j].F;
			}
			//printf("id = %d\n", id);
			for(int j = 0; j < sz; j++) {
				//printf("%d %d\n", v[j].F, abs(v[j].S - id));
				tmp += 1LL * v[j].F * abs(v[j].S - id);
			}
			v.clear();
			if(now + b > pp) v.push_back({b + now - pp, i}), now = now + b - pp; 
			else now = 0;
		}
		if(ans == -1) ans = tmp;
		else ans = min(ans, tmp);
		while(sum % pp == 0) sum /= pp;
	}
	if(sum != 1) {
		ll tmp = 0;
		vector<pii> v;
		ll now = 0;
		for(int i = 0; i < n; i++) {
			int b = a[i] % sum;
			if(now + b < sum) {
				v.push_back({b, i});
				now += b;
				continue;
			}
			v.push_back({sum - now, i});
			int sz = int(v.size());
			int id = -1;
			ll tot = 0;
			//printf("v:\n");
			//for(pii s : v) printf("%d %d\n", s.F, s.S);
			for(int j = 0; j < sz; j++) {
				if(tot < (sum + 1) / 2 && tot + v[j].F >= (sum + 1) / 2) {
					id = v[j].S;
					break;
				}
				tot += v[j].F;
			}
			//printf("id = %d\n", id);
			for(int j = 0; j < sz; j++) {
				//printf("%d %d\n", v[j].F, abs(v[j].S - id));
				tmp += 1LL * v[j].F * abs(v[j].S - id);
			}
			v.clear();
			if(now + b > sum) v.push_back({b + now - sum, i}), now = b + now - sum; 
			else now = 0;
		}
		if(ans == -1) ans = tmp;
		else ans = min(ans, tmp);
	}
	printf("%lld\n", ans);
	return 0;
}
