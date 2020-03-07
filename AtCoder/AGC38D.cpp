#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
const int maxn = 2e5 + 10;
int n, q;
ll m;
int p[maxn], sz[maxn];
int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}
vector<pii> edges[2];
bool Union(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return 0;
	if(sz[x] < sz[y]) swap(x, y);
	p[y] = x, sz[x] += sz[y];
	return 1;
}
int main() {
	scanf("%d%lld%d", &n, &m, &q);
	for(int i = 0; i < q; i++) {
		int x, y, c;
		scanf("%d%d%d", &x, &y, &c);
		edges[c].push_back({x, y});
	}
	if(m == n - 1 && !edges[1].empty())
		return puts("No"), 0;
	
	for(int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
	int com = n;
	for(auto p : edges[0]) 
		if(Union(p.F, p.S)) com--;
	for(auto p : edges[1]) 
		if(find(p.F) == find(p.S)) return puts("No"), 0;

	if(com != 2 && m <= n - com + 1LL * com * (com - 1) / 2) 
		puts("Yes");
	else puts("No");
	return 0;
}
