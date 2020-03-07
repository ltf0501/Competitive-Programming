#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
typedef long long ll;
char s[maxn];
int f[maxn];
int main() {
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i < maxn; i++) 
		f[i] = (f[i - 1] + f[i - 2]) % mod;
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++) {
		if(s[i] == 'w' || s[i] == 'm') return puts("0"), 0;
	}
	int ans = 1;
	int cntu = 0, cntn = 0;
	for(int i = 0; i <= n; i++) {
		if(i < n && s[i] == 'u') cntu++;
		if(i < n && s[i] == 'n') cntn++;
		if(cntu && (i == n || s[i] != 'u')) {
			ans = 1LL * ans * f[cntu] % mod;
			cntu = 0;
		}
		if(cntn && (i == n || s[i] != 'n')) {
			ans = 1LL * ans * f[cntn] % mod;	
			cntn = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
