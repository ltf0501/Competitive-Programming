#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
vector<int> v[kN];

int prep[kN];
vector<int> pr;

int cc[kN];
void pre() {
	for(int i = 2; i < kN; i++) {
		if(!prep[i]) pr.push_back(i), prep[i] = i;
		for(int j = 0; j < int(pr.size()) && 1LL * i * pr[j] < kN; j++) {
			prep[i * pr[j]] = pr[j];
			if(i % pr[j] == 0) break;
		}
	}
}
int main() {
	pre();
	int n; scanf("%d", &n);
	for(int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		while(x != 1) {
			int p = prep[x];
			int cnt = 0;
			while(x % p == 0) x /= p, cnt++;
			v[p].push_back(cnt);
		}
	}
	long long ans = 1;
	for(int p : pr) if(v[p].size() >= n - 1) { 
		if(v[p].size() < n) v[p].push_back(0);
		sort(v[p].begin(), v[p].end());
		int x = v[p][1];
		for(int i = 0; i < x; i++) ans *= p;
	}
	printf("%lld\n", ans);
	return 0;
}
