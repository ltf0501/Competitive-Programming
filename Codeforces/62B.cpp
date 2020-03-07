#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int maxn = 2e5 + 10;
char c[maxn], s[maxn];
vector<int> pos[26];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	for(int i = 0; i < 26; i++) pos[i].push_back(-INF);
	for(int i = 0; i < k; i++) pos[s[i] - 'a'].push_back(i);
	for(int i = 0; i < 26; i++) pos[i].push_back(INF);
	for(int i = 0; i < n; i++) {
		scanf("%s", c);
		ll ans = 0;
		int len = strlen(c);
		for(int j = 0; j < len; j++) {
			if(pos[c[j] - 'a'].size() == 2) ans += len;
			else {
				int id = lower_bound(pos[c[j] - 'a'].begin(), pos[c[j] - 'a'].end(), j) - pos[c[j] - 'a'].begin();
				ans += min(pos[c[j] - 'a'][id] - j, j - pos[c[j] - 'a'][id - 1]);	
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
