#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int a[maxn];
int le[maxn], ri[maxn];
ll suf[maxn], suf2[maxn];
ll ans[maxn];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	stack<int> s;
	s.push(0);
	for(int i = 1; i <= n; i++) {
		while(a[s.top()] >= a[i]) s.pop();
		le[i] = i - s.top();
		s.push(i);
	}
	while(!s.empty()) s.pop();
	s.push(n + 1);
	for(int i = n; i >= 1; i--) {
		while(a[s.top()] > a[i]) s.pop();
		ri[i] = s.top() - i;
		s.push(i);
	}
	for(int i = 1; i <= n; i++) {
		int l = le[i], r = ri[i];
		if(l > r) swap(l, r);	
		suf[l] += a[i];
		suf2[r] += 1ll * a[i] * l, suf2[l] -= 1ll * a[i] * l;
		suf2[l + r - 1] += 1ll * a[i] * (l + r), suf[l + r - 1] -= a[i];
		suf2[r] -= 1ll * a[i] * (l + r), suf[r] += a[i];
	}
	ll a = 0, b = 0;
	for(int i = n; i >= 1; i--) {
		a += suf[i], b += suf2[i];
		ans[i] = a * i + b;
	}
	int q;
	scanf("%d", &q);
	while(q--) {
		int x;
		scanf("%d", &x);
		printf("%.12f\n", ans[x] / double(n - x + 1));
	}
	return 0;
}
