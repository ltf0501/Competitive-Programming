#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 1.5e5 + 10;
const int kT = 100;
const int kMod = 998244353;

int n, q;
vector<int> g[kN];
int deg[kN];
bool isheavy[kN];
int que[kN];

void add(int &a, int b) {
	a += b;
	if(a >= kMod) a -= kMod;
	if(a < 0) a += kMod;
}
int pw(int a, int n) {
	int res = 1;
	while(n) {
		if(n & 1) res = 1LL * res * a % kMod;
		n >>= 1, a = 1LL * a * a % kMod;
	}
	return res;
}
int Inv(int a) {return pw(a, kMod - 2);}

int bit[kN];
void update(int x, int d) {
	for(int i = x; i <= n; i += i & -i) add(bit[i], d);
}
int query(int x) {
	int res = 0;
	for(int i = x; i; i -= i & -i) add(res, bit[i]);
	return res;
}

int in[kN], out[kN], dfs_clock;
int sz[kN], p[kN], pre[kN], preson[kN];
void dfs(int u, int fa = 0, int p1 = 0, int p2 = 0) {
	in[u] = ++dfs_clock;
	sz[u] = 1, p[u] = fa;
	pre[u] = p1, preson[u] = p2;
	for(int v : g[u]) if(v != fa) {
		dfs(v, u, isheavy[u] ? u : p1, isheavy[u] ? v : p2);
		sz[u] += sz[v];
	}
	out[u] = dfs_clock;
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1, x, y; i < n; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y), g[y].push_back(x);
		deg[x]++, deg[y]++;
	}
	for(int i = 1; i <= n; i++) isheavy[i] = (deg[i] >= kT);
	dfs(1);

	int invn = Inv(n);
	while(q--) {
		int op, u;
		scanf("%d%d", &op, &u);
		if(op == 1) {
			int d; scanf("%d", &d);
			update(in[u], d), update(in[u] + 1, kMod - d);
			int x = 1LL * sz[u] * Inv(n) % kMod * d % kMod;	
			update(1, x), update(n + 1, kMod - x);
			update(in[u], kMod - x), update(out[u] + 1, x);
			if(isheavy[u]) add(que[u], d);
			else {
				for(int v : g[u]) {
					if(v != p[u]) {
						int x = 1LL * (n - sz[v]) * invn % kMod * d % kMod;
						update(in[v], x), update(out[v] + 1, kMod - x);
					}
				}
			}
		}
		else {
			int ans = query(in[u]);
			pair<int, int> cur = {pre[u], preson[u]};
			while(cur.first) {
				add(ans, 1LL * (n - sz[cur.second]) * invn % kMod * que[cur.first] % kMod);
				cur = {pre[cur.first], preson[cur.first]}; 
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
