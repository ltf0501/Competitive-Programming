#include <bits/stdc++.h>
using namespace std;
const int kN = 2.5e5 + 10;

int n;
vector<int> g1[kN], g2[kN];
vector<tuple<int, int, int, int>> ans;
void print(tuple<int, int, int, int> p) {printf("%d %d %d %d\n", get<0>(p), get<1>(p), get<2>(p), get<3>(p));}

int in[kN], out[kN], dfs_clock;
int anc[20][kN];
void dfs1(int u, int fa) {
	anc[0][u] = fa;
	in[u] = ++dfs_clock;
	for(int v : g1[u]) 
		if(v != fa) dfs1(v, u);
	out[u] = dfs_clock;
}
bool ancestor(int x, int y) {return in[x] <= in[y] && out[x] >= out[y];}

int p[kN];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
void dfs2(int u, int fa) {
	for(int v : g2[u]) if(v != fa) {
		dfs2(v, u);
		int x = find(v);
		if(ancestor(x, u)) {
			int w = u;
			for(int i = 18; i >= 0; i--)
				if(ancestor(x, anc[i][w]) && find(anc[i][w]) != x) w = anc[i][w];
			p[w] = x;
			ans.emplace_back(w, anc[0][w], v, u);
		}
		else {
			p[x] = anc[0][x];
			ans.emplace_back(x, anc[0][x], v, u);
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g1[x].push_back(y), g1[y].push_back(x);
	}
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		g2[x].push_back(y), g2[y].push_back(x);
	}

	dfs1(1, 0); out[0] = dfs_clock;
	for(int j = 1; j <= 18; j++)
		for(int i = 1; i <= n; i++) anc[j][i] = anc[j - 1][anc[j - 1][i]];
	
	for(int i = 1; i <= n; i++) p[i] = i;
	dfs2(1, 0);
	printf("%d\n", n - 1);
	for(auto p : ans) print(p);
	return 0;
}
