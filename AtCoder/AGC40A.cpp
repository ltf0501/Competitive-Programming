#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
typedef long long ll;
int n;
char s[maxn];
int pre[maxn];
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int mn = 0;
	int big = 0, small = 0;
	ll ans = 0;
	for(int i = 1; i <= n + 1; i++) {
		if(i <= n && s[i] == '>') big++;
		if(i <= n && s[i] == '<') small++;
		if(i == n + 1 || s[i] != '>') {
			ans += 1LL * big * (big + 1) / 2;
			big = 0;
		}
		if(i == n + 1 || s[i] != '<') {
			
		}

	}
	return 0;
}

