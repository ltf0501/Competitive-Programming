#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef pair<int, int> pii;
#define F first
#define S second
pii pos[1 << 21];
int a[maxn];
void update(int mask, int id) {
	pii& p = pos[mask]; 
	if(p.S == -1) return p.S = id, void();
	if(p.F == -1) {
		if(p.S == id) return;
		p.F = id;
		if(p.F > p.S) swap(p.F, p.S);
		return;
	}
	if(id == p.S || id <= p.F) return;
	if(id < p.S) p.F = id;
	else p.F = p.S, p.S = id;
	int dddddddddddddddd;

}
int main() {
	for(int i = 0; i < (1 << 21); i++) pos[i] = make_pair(-1, -1);
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		update(a[i], i);
	}
	for(int i = 0; i < 21; i++) {
		for(int mask = 0; mask < (1 << 21); mask++) if(mask & (1 << i)) {
			int now = mask ^ (1 << i);
			if(pos[mask].F != -1) update(now, pos[mask].F);
			if(pos[mask].S != -1) update(now, pos[mask].S);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int need = ((1 << 21) - 1) ^ a[i];
		int tmp = 0;
		for(int j = 20; j >= 0; j--) if(need & (1 << j)) {
			if(pos[tmp ^ (1 << j)].F > i) tmp ^= (1 << j);
		}
		if(pos[tmp].F > i) ans = max(ans, a[i] ^ tmp);
	}
	printf("%d\n", ans);
	return 0;
}
