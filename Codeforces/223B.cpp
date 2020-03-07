#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
char s[kN], t[kN];
vector<int> s_pos[26], t_pos[26];
int pre[kN], suf[kN];
void die() {
	puts("No"); exit(0);
}
int main() {
	scanf("%s %s", s + 1, t + 1);
	int n = strlen(s + 1), m = strlen(t + 1);
	for(int i = 1; i <= n; i++) s_pos[s[i] - 'a'].push_back(i);
	for(int i = 1; i <= m; i++) t_pos[t[i] - 'a'].push_back(i);

	for(int i = 1; i <= n; i++) {
		if(s[i] == t[pre[i - 1] + 1]) pre[i] = pre[i - 1] + 1;
		else pre[i] = pre[i - 1];
	}
	suf[n + 1] = m + 1;
	for(int i = n; i >= 1; i--) {
		if(s[i] == t[suf[i + 1] - 1]) suf[i] = suf[i + 1] - 1;
		else suf[i] = suf[i + 1];
	}

	for(int j = 0; j < 26; j++) {
		auto ss = s_pos[j], tt = t_pos[j];
		if(ss.empty() && tt.empty()) continue;
		if(ss.empty() || tt.empty()) die();
		int cur = 0;
		for(int x : ss) {
			while(cur < int(tt.size()) && (pre[x - 1] < tt[cur] - 1 || suf[x + 1] > tt[cur] + 1)) cur++;
			if(cur == int(tt.size())) die();
		}
		if(cur == int(tt.size())) die();
	}
	puts("Yes");
	return 0;
}
