#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 10;
typedef pair<int, int> pii;
#define F first
#define S second
vector<int> p;
int f[maxn];
vector<int> ans[maxn];
void pre() {
	f[1] = 1;
	for(int i = 2; i < maxn; i++) {
		if(!f[i]) p.push_back(i), f[i] = i;
		for(int j = 0; j < (int)p.size() && 1LL * i * p[j] < maxn; j++) {
			f[i * p[j]] = p[j];
			if(i % p[j] == 0) break;
		}
	}
	for(int x : p) {
		int k = 0;
		int cur = 0;
		ans[x].push_back(0);
		for(int i = 1, now = x; now < maxn; now *= x, i++) {
			while(cur < i) {
				k += x;
				int tmp = x;
				while(k % tmp == 0) 
					cur++, tmp *= x;
				
			}
			ans[x].push_back(k);
		}
	}
}
int main() {
	pre();
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		if(n == 1) {
			puts("0");
			continue;
		}
		vector<pii> v;
		while(n != 1) {
			int x = f[n], cnt = 0;
			while(n % x == 0) cnt++, n /= x;
			v.push_back({x, cnt});
		}
		int res = 0;
		for(pii s : v) {
			res = max(res, ans[s.F][s.S]);
		}
		printf("%d\n", res);
	}
	return 0;
}
