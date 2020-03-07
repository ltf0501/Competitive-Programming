#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
#define ALL(v) v.begin(), v.end()
int a[maxn];
int pre[maxn], nxt[maxn];
int cur[maxn];
vector<int> v;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		v.clear();
		int n;scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]), v.push_back(a[i]);
		sort(ALL(v));
		v.resize(unique(ALL(v)) - v.begin());
		for(int i = 1; i <= n; i++) a[i] = lower_bound(ALL(v), a[i]) - v.begin() + 1;
		for(int i = 1; i <= n; i++) cur[i] = n + 1;
		int m = v.size();
		for(int i = n; i >= 1; i--) {
			nxt[i] = cur[a[i]];
			cur[a[i]] = i;
		}
		for(int i = 1; i <= n; i++) cur[i] = 0;
		for(int i = 1; i <= n; i++) {
			pre[i] = cur[a[i]];
			cur[a[i]] = i;
		}
		int le = 0, ri = 0;
		if(a[1] == 1) {
			int id = 1;
			int k = 1;
			while(id <= n) {
				bool flag = 1;
				while(id <= n && nxt[id] == id + 1) id++;
				if(nxt[id] != id + 1) {le = m - k; break;}
				id++, k++;
			}
		}
		if(a[n] == m) {
			int id = n;
			int k = 1;
			while(id >= 1) {
				bool flag = 1;
				while(id >= 1 && nxt[id] == id - 1) id--;
				if(nxt[id] != id - 1) {ri = m - k; break;}
				id--, k++;
			}
		}
		printf("le = %d, ri = %d\n", le, ri);
		int ans = min({m - 1, le, ri});
		printf("%d\n", ans);
	}
	return 0;
}
