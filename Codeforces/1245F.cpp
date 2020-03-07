#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll pw[40];
int mylog(int n) {
	if(n == 0) return 0;
	return log2(n);
}
ll check1(int a, int len) {
//	if(a % 2 == 0 && len == -1) len = 0;
	//printf("a = %d, len = %d\n", a, len);
	ll res = 0;
	ll now = 1;
	for(int i = len; i >= 0; i--) {
		if(a & (1 << i)) res += 2 * now * pw[i];
		else now *= 2;
	}
	res += now;
	//printf("res = %lld\n", res);
	return res;
}
ll check2(int a, int b, int len) {
	//printf("a = %d, b = %d, len = %d\n", a, b, len);
	ll res = 0;
	for(int i = len; i >= 0; i--) {
		bool aa = (a & (1 << i)), bb = (b & (1 << i));
		if(bb) swap(a, b), swap(aa, bb);
		if(aa && bb) {
			res += pw[i]; // a = 0, b = 0
			res += check1(a, i - 1); // a = 1, b = 0
			res += check1(b, i - 1); // a = 0, b = 1
			return res;
		}
		else if(aa) {
			res += check1(b, i - 1); //a = 0, b = 0
			 // a = 1, b = 0
		}
		else {
			// a = 0, b = 0		
		}
	}
	//printf("rres = %lld\n", res);
	return res;
}
ll solve(int a, int b) {
	if(a > b) swap(a, b);
	if(a == 0) return b + 1;
	int na = mylog(a), nb = mylog(b); 	
	int k = b >> (na + 1);
	//printf("k = %d\n", k);
	ll ans = k * check1(a, na) + check2(a, b, na); 
	//printf("%lld\n", ans);
	return ans;
}
int main() {
	pw[0] = 1;
	for(int i = 1; i < 35; i++) pw[i] = pw[i - 1] * 3;
	int T;
	scanf("%d", &T);
	while(T--) {
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%lld\n", solve(r, r) - 2 * solve(l - 1, r) + solve(l - 1, l - 1));
	}
	return 0;
}
//98 1180 66084
