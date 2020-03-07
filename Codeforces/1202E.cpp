#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
struct node {
	int ch[26], cnt, fail;
} trie[maxn];
int num;
int newnode() {
	memset(trie[num].ch, 0, sizeof(trie[num].ch));
	trie[num].cnt = 0;
	trie[num].fail = 0;
	return num++;
}
void insrt(string a) {
	int len = (int)a.size();
	int cur = 0;
	for(int i = 0; i < len; i++) {
		if(trie[cur].ch[a[i] - 'a'] == 0)
			trie[cur].ch[a[i] - 'a'] = newnode();
		cur = trie[cur].ch[a[i] - 'a'];
	}
	trie[cur].cnt++;
}
void build_fail() {
	queue<int> q;
	for(int i = 0; i < 26; i++) {
		if(trie[0].ch[i]) {
			q.push(trie[0].ch[i]);
			trie[0].fail = 0;
		}
	}
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i = 0; i < 26; i++) {
			if(trie[x].ch[i]) {
				trie[trie[x].ch[i]].fail = trie[trie[x].fail].ch[i];
				trie[trie[x].ch[i]].cnt += trie[trie[trie[x].ch[i]].fail].cnt;
				q.push(trie[x].ch[i]);
			}
			else trie[x].ch[i] = trie[trie[x].fail].ch[i];
		}
	}
}
string t, s[maxn];
int pre[maxn], suf[maxn];
int main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	int n = (int)t.size();
	int m;
	cin >> m;
	int root = newnode();
	for(int i = 0; i < m; i++) {
		cin >> s[i];
		insrt(s[i]);
	}
	build_fail();
	int cur = 0;
	for(int i = 0; i < n; i++) {
		cur = trie[cur].ch[t[i] - 'a'];
		pre[i] = trie[cur].cnt;
	}
	num = 0;
	root = newnode();
	reverse(t.begin(), t.end());
	for(int i = 0; i < m; i++) reverse(s[i].begin(), s[i].end());
	for(int i = 0; i < m; i++) insrt(s[i]);
	build_fail();
	cur = 0;
	for(int i = 0; i < n; i++) {
		cur = trie[cur].ch[t[i] - 'a'];
		suf[i] = trie[cur].cnt;
	}
	reverse(suf, suf + n);
	ll ans = 0;
	for(int i = 1; i < n; i++) ans += 1ll * pre[i - 1] * suf[i];
	cout << ans << '\n';
	return 0;
}
