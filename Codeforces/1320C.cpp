#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
const int kN = 2e5 + 10;
const int kM = 1e6 + 10;
const ll kInf = 1e16;

int n, m, p;
pii a[kN], b[kN];
tuple<int, int, int> c[kN];
ll bit[kM];
void add(int x, ll d) {
	for(int i = x; i < kM; i += i & -i) bit[i] += d;
}
ll query(int x) {
	ll res = 0;
	for(int i = x; i; i -= i & -i) res += bit[i];
	return res;
}
int main() {
	scanf("%d%d%d", &n, &m, &p);	
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].F, &a[i].S);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &b[i].F, &b[i].S);
	}
	for(int i = 1, x, y, z; i <= p; i++) {
		scanf("%d%d%d", &x, &y, &z);
		c[i] = make_tuple(x, y, z);
	}
	sort(a + 1, a + n + 1), sort(b + 1, b + m + 1), sort(c + 1, c + p + 1);
	ll ans = -kInf;

	stack<int> st;
	for(int i = 1; i <= m; i++) {
		while(!st.empty() && b[st.top()].S >= b[i].S) st.pop();
		st.push(i);
	}
	set<pii> s;
	while(!st.empty()) {
		int x = st.top(); st.pop();
		s.insert({b[x].F, x});
	}

	for(int i = 1, j = 1; i <= n; i++) {
		auto cal = [&](int id) {
			return query(b[id].F - 1) - b[id].S;
		};
		while(j <= p && get<0>(c[j]) < a[i].F) { 
			int pos = get<1>(c[j]);
			add(pos, get<2>(c[j]));
			j++;
			while(int(s.size()) >= 2) {
				auto it = s.lower_bound({pos, -kInf});
				if(it == s.begin() || it == s.end()) break;
				int id1 = prev(it)->S, id2 = it->S;


				if(cal(id2) >= cal(id1)) s.erase(--it);
				else break;
			}
		}
		int id = s.begin()->S;
		ll num = cal(id) - a[i].S;
		ans = max(ans, num);
	}
	printf("%lld\n", ans);
	return 0;
}
