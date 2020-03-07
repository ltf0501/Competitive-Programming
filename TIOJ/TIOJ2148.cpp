#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k;

int main() {
	scanf("%d%lld", &n, &k);
	priority_queue<ll> pq;
	for(int i = 0; i < n; i++) {
		ll x;
		scanf("%lld", &x); pq.push(x);
	}
	ll cnt = 0;
	while(true) {
		ll a = pq.top(); pq.pop();
		ll b = pq.top(); pq.pop();
		if(a + b < k) return printf("%lld\n", cnt), 0;
		cnt++;
		ll c = (a + b) / 3, d = (a + b) % 3;
		for(int i = 0; i < d; i++) pq.push(c + 1);	
		for(int i = 0; i < 3 - d; i++) pq.push(c);
	}
	return 0;
}
