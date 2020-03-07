#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const ll kInf = (1LL << 62) - 1;
#define F first
#define S second
ll x_0, y_0, ax, ay, bx, by;
ll p, q, t;
vector<pll> v;
ll dis(pll a, pll b) {
	return abs(a.F - b.F) + abs(a.S - b.S);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> x_0 >> y_0 >> ax >> ay >> bx >> by;
	cin >> p >> q >> t;
	pll st = {p, q};
	pll cur = {x_0, y_0};
	v.push_back(cur);
	while(1) {
		if((kInf - bx) / ax < cur.F || (kInf - by) / ay < cur.S) break;
		cur.F = ax * cur.F + bx, cur.S = ay * cur.S + by;
		v.push_back(cur);
	}
	int n = int(v.size());
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			ll l = dis(v[i], v[j]);
			ll dl = min(dis(st, v[i]), dis(st, v[j]));
			if(l <= t - dl) ans = max(ans, j - i + 1);
		}
	}
	cout << ans << '\n';
	return 0;
}
