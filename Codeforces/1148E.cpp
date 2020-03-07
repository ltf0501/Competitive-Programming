#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
const int kN = 3e5 + 10;

int n;
pii a[kN], b[kN];
int diff[kN];
vector<tuple<int, int, int>> ans;
void gao(int i, int j, int d) {
	ans.emplace_back(i, j, d);
	a[i].F += d, a[j].F -= d;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		a[i] = {x, i};
	}
	for(int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		b[i] = {x, i};
	}
	sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
	ll tmp = 0;
	for(int i = 1; i <= n; i++) {
		diff[i] = b[i].F - a[i].F;
		tmp += diff[i];
		if(tmp < 0) return puts("NO"), 0;
	}
	if(tmp != 0) return puts("NO"), 0;

	stack<pii> s;
	for(int i = 1; i <= n; i++) {
		if(diff[i] > 0) {
			s.emplace(i, diff[i]); 
			continue;
		}
		while(diff[i] < 0 && !s.empty()) {
			pii t = s.top(); s.pop();
			int id = t.F, delta = t.S;
			int d = min(-diff[i], delta);
			gao(a[id].S, a[i].S, d);
			diff[i] += d;
			if(delta > d) s.emplace(id, delta - d);
		}
		//if(diff[i] != 0) return puts("NO"), 0;
	}

	puts("YES");
	printf("%d\n", int(ans.size()));
	for(auto p : ans) printf("%d %d %d\n", get<0>(p), get<1>(p), get<2>(p));
	return 0;
}
