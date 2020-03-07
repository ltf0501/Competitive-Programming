#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
char s[kN];
int pre[26][kN];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 26; j++) pre[j][i] = pre[j][i - 1];
		pre[s[i] - 'a'][i]++;
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if(l == r) {puts("Yes"); continue;}
		int cnt = 0;
		for(int j = 0; j < 26; j++) cnt += (pre[j][r] != pre[j][l - 1]);
		if(cnt >= 3 || s[l] != s[r]) puts("Yes");
		else puts("No");
	}
	return 0;
}
