#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
const int INF = 1e9;
int x[maxn], y[maxn], z[maxn];
bool vis[maxn];
int n;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d%d%d", &x[i], &y[i], &z[i]);
	for(int i = 0; i < n; i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		vector<int> v;
		int mi = INF;
		for(int j = i + 1; j < n; j++) if(!vis[j]) {
			int d = abs(x[i] - x[j]);
			if(d < mi) mi = d, v.clear(), v.push_back(j);
			else if(d == mi) v.push_back(j);
		}
		vector<int> tmp;
		mi = INF;
		for(int j : v) {
			int d = abs(y[i] - y[j]);
			if(d < mi) mi = d, tmp.clear(), v.push_back(j);
			else if(d == mi) v.push_back(j);
		}
		v = tmp; tmp.clear();
		mi = INF;
		for(int j : v) {
			int d = abs(z[i] - z[j]);
			if(d < mi) mi = d, tmp.clear(), v.push_back(j);
			else if(d == mi) v.push_back(j);
		}
		int j = v[0];
		vis[j] = 1;
		printf("%d %d\n", i, j);
	}
	return 0;
}
