#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
const int kN = 2e5 + 10;

int n;
pii a[kN];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i].F);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i].S);
	sort(a + 1, a + n + 1);
	ll ans = 0;
	for(int i = 1; i <= n; ) {
		priority_queue<int> pq;
		pq.push(a[i].S);
		ll sum = a[i].S;
		int cur = a[i].F;
		int j = i + 1;
		while(!pq.empty()) {
			while(j <= n && a[j].F <= cur) pq.push(a[j].S), sum += a[j++].S;
			sum -= pq.top(); pq.pop();
			ans += sum;
			cur++;
		} 
		i = j;
	}
	printf("%lld\n", ans);
	return 0;
}
