#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10; 
typedef pair<int, int> pii;
#define F first
#define S second

int n;
vector<int> g[kN];
vector<pii> edges;
int ans[kN];

int main() {
	scanf("%d", &n);
	for(int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		int s = edges.size();
		g[x].push_back(s), g[y].push_back(s);
		edges.emplace_back(x, y);
	}
	for(int i = 0; i < n; i++) ans[i] = -1;
	for(int i = 1; i <= n; i++) if(int(g[i].size()) >= 3) {
		for(int j = 0; j < 3; j++) ans[g[i][j]] = j;
		int cur = 3;
		for(int j = 0; j < n - 1; j++) {
			if(ans[j] == -1) ans[j] = cur++;
			printf("%d\n", ans[j]);
		}
		return 0;
	}
	for(int i = 0; i < n - 1; i++) printf("%d\n", i); 
	return 0;
}
