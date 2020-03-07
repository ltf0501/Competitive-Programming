#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 2e5 + 10;
const ll kInf = 3'000'000'000'000'000'000ll;

int n;
ll t;
ll a[kN], b[kN];
int x[kN];
int main() {
	scanf("%d%lld", &n, &t);
	for(int i = 1; i <= n; i++) scanf("%lld", a + i);
	for(int i = 1; i <= n; i++) scanf("%d", x + i);
	for(int i = 1; i <= n; i++)
		if(x[i] < i) return puts("No"), 0;
	for(int i = 1; i < n; i++)
		if(x[i] > x[i + 1]) return puts("No"), 0;

	b[n] = kInf;
	for(int i = n - 1, cur = n; i >= 1; i--) {
		int c = x[i];			
		if(c != cur && c != i) return puts("No"), 0;
		if(c == cur) {
			if(a[i + 1] + t >= b[i + 1]) return puts("No"), 0;
			b[i] = b[i + 1] - 1;
		}
		else {
			b[i] = a[i + 1] + t - 1;
		}
		if(b[i] <= 0) return puts("No"), 0;
		cur = c;
	}
	puts("Yes");
	for(int i = 1; i <= n; i++) printf("%lld ", b[i]); puts("");
	return 0;
}
