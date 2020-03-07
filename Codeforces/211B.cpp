#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char s[maxn];
int nxt[26][maxn];
int n;

int get_next(int id, int mask) {
	int res = n;
	for(int i = 0; i < 26; i++) 
		if((mask & (1 << i)) == 0) res = min(res, nxt[i][id]);
	return res;
}
int main() {
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < 26; i++) nxt[i][n] = n;
	for(int i = n - 1; i >= 0; i--) {
		for(int j = 0; j < 26; j++) nxt[j][i] = nxt[j][i + 1];
		nxt[s[i] - 'a'][i] = i;
	}
	for(int i = 0; i < n; i++) {
		int prv = (i == 0) ? 30 : s[i - 1] - 'a';
		int cur_idx = i;
		int cur_mask = (1 << (s[i] - 'a'));
		while(cur_idx < n) {
			if((cur_mask & (1 << prv)) == 0) v[vsz++] = cur_mask;
			else break;
			cur_idx = get_next(cur_idx, cur_mask);
			if(cur_idx < n) cur_mask |= (1 << (s[cur_idx] - 'a'));
		}
	}
	sort(v, v + vsz);
	int q;
	scanf("%d", &q);
	while(q--) {
		char t[30];
		scanf("%s", t);
		int mask = 0;
		for(int i = 0; i < strlen(t); i++) mask |= (1 << (t[i] - 'a'));
		printf("%d\n", lower_bound(v, v + vsz, mask + 1) - lower_bound(v, v + vsz, mask));
	}
	return 0;
}
