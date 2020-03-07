#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
vector<int> p;
bool notp[maxn];
void pre(ll a) {
	for(int i = 2; i < a; i++) {
		if(!notp[i]) p.push_back(i), notp[i] = 1;
		for(int j = 0; j < (int)p.size() && 1LL * i * p[j] < a; j++)
			notp[i * p[j]] = 1;
	}
	printf("prime size = %d\n", (int)p.size());
}

map<ll, int> mp;
int main() {
	ll A; scanf("%lld", &A);
	pre((ll)(sqrt(A + 0.5)));
	mp[1] = 1;
	int ans = 0;
	ll cal = 0;
	for(int x : p) {
		ll cur = 1;
		unordered_map<ll, int> tmp;
		tmp.reserve(65536); tmp.max_load_factor(0.25);
		printf("primr = %d\n", x);
		for(int i = 1; ; i++) {
			cur *= x;
			if(cur >= A) break;
			for(auto s : mp) {
		//		printf("s.first = %lld, s.second = %d\n", s.first, s.second);
		//		printf("now = %lld\n", s.first * (cur + 1));
				if(s.first * (cur + 1) > A) break;
				tmp[s.first * (cur + 1)] += s.second;
				cal++;
			}
		}
		for(auto s : tmp) mp[s.first] += s.second, cal++;
	}
	printf("cal = %lld\n", cal);
	ans += (mp.find(A) != mp.end() ? mp[A] : 0);
	ll t = A;

	return 0;
}
