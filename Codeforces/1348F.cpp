#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
typedef pair<int, int> pii;
#define F first
#define S second

int n;
int l[kN], r[kN];
vector<pii> pos[kN];
int id[kN], ans[kN];

int bit[kN];
void update(int x, int d) {
	for(int i = x; i <= n; i += i & -i) bit[i] = min(bit[i], d);
} 
int query(int x) {
	int res = n + 1;
	for(int i = x; i; i -= i & -i) res = min(res, bit[i]);
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &l[i], &r[i]);
		pos[l[i]].emplace_back(r[i], i); 
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for(int i = 1, j = 1; i <= n; i++) {
		for(auto p : pos[i]) pq.emplace(p);
		auto p = pq.top(); pq.pop();
		id[i] = p.S;
		ans[p.S] = i;
	}

	for(int i = 1; i <= n; i++) bit[i] = n + 1;
	for(int i = n; i > 0; i--) {
		if(query(r[id[i]]) <= i) {
			for(int j = i + 1; j <= n; j++) {
				if(l[id[j]] <= i) {
					puts("NO");
					for(int k = 1; k <= n; k++) printf("%d ", ans[k]); puts("");
					swap(ans[id[i]], ans[id[j]]);
					for(int k = 1; k <= n; k++) printf("%d ", ans[k]); puts("");
					return 0;
				}
			}
		}

		update(i, l[id[i]]);
	}
	puts("YES");
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]); puts("");
	return 0;
}
