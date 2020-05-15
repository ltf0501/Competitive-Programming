#include <bits/stdc++.h>
using namespace std;
const int kN = 1e3 + 10;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
typedef pair<int, int> pii;
#define F first
#define S second

int n, m;
char c[kN][kN];
bool vis[kN][kN];
int dis[kN][kN];
bool inside(int x, int y) {return x >= 0 && x < n && y >= 0 && y < m;}
bool check(int x, int y) {
	bool res = 0;
	for(int i = 0; i < 4; i++) res |= (inside(x + dx[i], y + dy[i]) && c[x][y] == c[x + dx[i]][y + dy[i]]);
	return res;
}
int main() {
	int T;
	scanf("%d%d%d", &n, &m, &T);
	for(int i = 0; i < n; i++) scanf("%s", c[i]);

	queue<pii> q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(check(i, j)) vis[i][j] = 1, q.emplace(i, j);
		}
	}
	bool flag = q.empty();
	
	while(!q.empty()) {
		pii p = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			int a = p.F + dx[i], b = p.S + dy[i];
			if(!inside(a, b) || vis[a][b]) continue;
			vis[a][b] = 1, dis[a][b] = dis[p.F][p.S] + 1;
			q.emplace(a, b);
		}
	}

	while(T--) {
		int x, y;
		long long t; scanf("%d%d%lld", &x, &y, &t);
		x--, y--;
		if(flag) {
			putchar(c[x][y]);
			puts("");
			continue;
		}
		t -= dis[x][y];
		//printf("%d %d: dis = %d\n", x, y, dis[x][y]);
		printf("%d\n", (t > 0 && (t & 1)) ? (c[x][y] - '0') ^ 1 : (c[x][y] - '0'));
	}
	return 0;
}
