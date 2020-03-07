//#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 5e3 + 10;
vector<int> prime;
int fac[kN], divisor[kN][kN];
int cnt[kN];
int n, m;
void pre() {
	for(int i = 2; i <= 5000; i++) {
		if(!fac[i]) fac[i] = i, prime.push_back(i), div[i][i] = 1;
		for(int p : prime) {
			if(1LL * i * p >= kN) break;
			fac[i * p] = p;
			if(i % p == 0) break;
		}
	}
	m = int(prime.size());
	for(int i = 2; i < kN; i++) {
		int cur = i;
		for(int j = 0; j < m; j++) 
			while(cur % j == 0) divisor[i][j]++, cur /= j; 
	}
	for(int i = 2; i < kN; i++) {
		for(int j = 0; j < m; j++) divisor[i][j] += divisor[i - 1][j];
	}
}
int main() {
	pre();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	ll ans = 0;
	for(int i = 1; i < kN; i++) {
		int sum = 0;
		for(int j = 0; j < m; j++) sum += divisor[i][j];
		ans += 1LL * cnt[i] * sum;
	}

	return 0;
}
