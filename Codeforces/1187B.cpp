#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
char c[maxn],d[maxn];
vector<int> v[30];
int n, m;
int cnt[30];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < 26; i++) v[i].push_back(0);
	scanf("%s", c + 1);
	for(int i = 1; i <= n; i++) v[c[i]-'a'].push_back(i);
	scanf("%d", &m);
	while(m--) {
		scanf("%s", d + 1);
		memset(cnt, 0, sizeof(cnt));
		int len = strlen(d + 1);
		for(int i = 1; i <= len; i++) cnt[d[i] - 'a']++;
		int ans = 0;
		for(int i = 0; i < 26; i++)
			ans = max(ans, v[i][cnt[i]]);
		printf("%d\n", ans);
	}
	return 0;
}
