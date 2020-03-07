#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 1e6 + 10;
char s[kN];
int pre[kN], suf[kN];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	ll ans = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'v' && s[i - 1] == 'v') cnt++;
		pre[i] = cnt;
	}
	cnt = 0;
	for(int i = n; i >= 1; i--) {
		if(s[i] == 'v' && s[i + 1] == 'v') cnt++;
		suf[i] = cnt;
	}
	for(int i = 1; i <= n; i++)
		if(s[i] == 'o') ans += 1LL * pre[i - 1] * suf[i + 1];
	printf("%lld\n", ans);
	return 0;
}
