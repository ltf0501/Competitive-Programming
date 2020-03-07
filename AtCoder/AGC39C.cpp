#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 998244353;
int n;
char s[maxn];
int cnt[maxn << 1];
int get_val(int k) {
	int res = 0;
	for(int i = 0; i < k; i++) {
		res = (2LL * res % mod + (s[i] - '0')) % mod;
	}
	return res;
}
void add(int& a, int b) {
	a += b;
	if(a >= mod) a -= mod;
}
void sub(int& a, int b) {
	a -= b;
	if(a < 0) a += mod;
}
int main() {
	scanf("%d", &n);
	scanf("%s", s);
	for(int k = 2; k <= 2 * n; k += 2) {
		if(2 * n % k != 0 || (2 * n / k) % 2 == 0) continue;
		int num = 0;
		add(num, get_val(k / 2));
		bool flag = 1;
		for(int j = k / 2; j < n; j++) {
			char t;
			int r = j % k;
			if(r < k / 2) t = s[r];
			else t = '0' + '1' - s[r - k / 2];
			if(t > s[j]) {flag = 0; break;}
			else if(t < s[j]) break;
		}
		if(flag) add(num, 1);
		add(cnt[k], num);
		int s = 2 * n / k;
		for(int l = 3; l <= s; l += 2) 
			if(s % l == 0) sub(cnt[k * l], cnt[k]);
	}
	int ans = 0;	
	for(int k = 2; k <= 2 * n; k += 2) 
		add(ans, 1LL * k * cnt[k] % mod);
	printf("%d\n", ans);
	return 0;
}
