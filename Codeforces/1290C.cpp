#include <bits/stdc++.h>
using namespace std;
const int kN = 3e5 + 10;
const int kInf = 1e8;
int n, k;
char s[kN];
vector<int> pos[kN];
int p[kN], sz[kN], tot[kN], ans[kN];
bool rev[kN];
pair<int, int> find(int x) {
	if(p[x] == x) return {x, rev[x] = 0};
	pair<int, int> tmp = find(p[x]);
	p[x] = tmp.first, rev[x] ^= tmp.second;
	return {p[x], rev[x]};
}
int num;
void Union(int x, int y, bool flag) {
	int a = find(x).first, b = find(y).first;
	flag ^= (rev[x] ^ rev[y]);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	p[b] = a, sz[a] += sz[b];
	rev[b] = flag;
	int tmp;
	if(flag) tmp = ans[a] + tot[b] - ans[b];
	else tmp = ans[a] + ans[b];
	num += min(tmp, tot[a] + tot[b] - tmp) - min(ans[a], tot[a] - ans[a]) - min(ans[b], tot[b] - ans[b]);
	tot[a] += tot[b];
	ans[a] = tmp;
}
int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	for(int i = 1; i <= k; i++) {
		int nc;
		scanf("%d", &nc);
		while(nc--) {
			int x; scanf("%d", &x);
			pos[x].push_back(i);
		}
	}

	for(int i = 1; i <= k + 1; i++) p[i] = i, sz[i] = 1, ans[i] = 1, tot[i] = 1;
	tot[k + 1] = kInf, ans[k + 1] = kInf;

	for(int i = 1, x, y; i <= n; i++) {
		if(pos[i].empty()) {printf("%d\n", num); continue;}
		if(int(pos[i].size()) == 1) x = pos[i][0], y = k + 1;
		else x = pos[i][0], y = pos[i][1];
		Union(x, y, s[i] == '0');
		printf("%d\n", num);
	}
	return 0;
}
