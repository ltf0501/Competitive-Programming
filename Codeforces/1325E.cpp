#include <bits/stdc++.h>
using namespace std;
const int kC = 1e6 + 10;
const int kN = 1e5 + 10;
int idx[kC];
vector<int> pr;
vector<int> g[kN];
bool vis[kN];
int dep[kN], fa[kN];
int q[kN];
void pre() {
	for(int i = 1; i < kC; i++) idx[i] = -1;
	idx[1] = -2;
	for(int i = 2; i < kC; i++) {
		if(idx[i] == -1) idx[i] = pr.size(), pr.push_back(i);
		for(int x : pr) {
			if(1LL * i * x >= kC) break;
			idx[i * x] = -2;
			if(i % x == 0) break;
		}
	}
	//for(int i = 1; i < 50; i++) printf("idx[%d] = %d\n", i, idx[i]);
	//printf("sz = %d\n", int(pr.size()));
}
void AddEdge(int x, int y) {
	//printf("(%d, %d)\n", x, y);
	g[x].push_back(y), g[y].push_back(x);
}
int main() {
	pre();
	int O = pr.size();
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		vector<int> tmp;
		if(x == 1) return puts("1"), 0;

		bool flag = 0;
		for(int p : pr) {
			if(x % p == 0) {
				int cnt = 0;
				while(x % p == 0) x /= p, cnt++;

				if(cnt & 1) {
					if(idx[x] != -2) AddEdge(idx[x], idx[p]);
					else AddEdge(idx[p], O);
				}
				else {
					if(x == 1) return puts("1"), 0;
					if(idx[x] != -2) AddEdge(O, idx[x]);
					else assert(0);
				}
				flag = 1;
				break;
			}
			if(p > 1000) break;
		} 
		if(!flag) AddEdge(idx[x], O);
	}

	//pr.push_back(1);
	//for(int i = 0; i <= O; i++) {
	//	if(!g[i].empty()) {
	//		printf("%d: ", pr[i]);
	//		for(int x : g[i]) printf("%d ", pr[x]); puts("");
	//	}
	//}
	
	int ans = 1'000'000'000;
	for(int i = 0; i <= O; i++) dep[i] = -1;
	pr.push_back(1);
	for(int i = 0; i <= O; i++) { 
		if(g[i].empty() || pr[i] > 1000) continue;
		int rear = 0;
		q[rear++] = i;
		dep[i] = 0, fa[i] = -1;
		for(int front = 0; front < rear; front++) {
			int u = q[front];
			bool flag = 1;
			for(int v : g[u]) {
				if(dep[v] >= 0) {
					if(v == fa[u] && flag) flag = 0;
					else ans = min(ans, dep[v] + dep[u] + 1);
				}
				else {
					dep[v] = dep[u] + 1;
					fa[v] = u;
					q[rear++] = v;
				}
			}
		}

		for(int i = 0; i < rear; i++) dep[q[i]] = -1;
	}
	if(ans == 1'000'000'000) ans = -1;
	printf("%d\n", ans);
	return 0;
}
