#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 7010;
ll a[maxn];
int b[maxn];
int n;
vector<int> g[maxn];
bool is(ll x, ll y) {
	for(int i = 0; i < 60; i++) 
		if((x & (1LL << i)) && !(y & (1LL << i))) return 1;
	return 0;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++)
			if(i != j && is(i, j)) g[i].push_back(j);
	return 0;
}
