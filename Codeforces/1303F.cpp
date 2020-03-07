#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define F first
#define S second
const int kN = 305;
const int kC = 2e6 + 10;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n, m, q;
int col[kN][kN];
int get_id(int x, int y) {
	return x * m + y;
}
bool ok(int x, int y) {return 0 <= x && x < n && 0 <= y && y < m;}
int p[kN * kN], sz[kN * kN];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
bool Union(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return 0;
	if(sz[x] < sz[y]) swap(x, y);
	p[y] = x, sz[x] += sz[y];
	return 1;
}
vector<pii> add[kC], sub[kC];
int ans[kC];
void gao(vector<pii> &events, int flag) {
	for(int i = 0; i < n * m; i++) p[i] = i, sz[i] = 1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) col[i][j] = 0;

	for(auto e : events) {
		int com = 1;
		int x = e.F / m, y = e.F % m;
		col[x][y] = 1;
		for(int i = 0; i < 4; i++) {
			int a = x + dx[i], b = y + dy[i];
			if(!ok(a, b)) continue;
			if(col[a][b]) com -= Union(get_id(x, y), get_id(a, b));
		}
		ans[e.S] += com * flag;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	int cnt = 0;
	for(int i = 0; i < q; i++) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		x--, y--;
		if(col[x][y] == c) continue;
		cnt = c;
		add[c].emplace_back(get_id(x, y), i);
		sub[col[x][y]].emplace_back(get_id(x, y), i);
		col[x][y] = c;
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) sub[col[i][j]].emplace_back(get_id(i, j), q);
	for(int i = 1; i <= cnt; i++) reverse(sub[i].begin(), sub[i].end());
	for(int i = 1; i <= cnt; i++) gao(add[i], 1);
	for(int i = 1; i <= cnt; i++) gao(sub[i], -1);
	for(int i = 1; i < q; i++) ans[i] += ans[i - 1];
	for(int i = 0; i < q; i++) printf("%d\n", ans[i]);
	return 0;
}
