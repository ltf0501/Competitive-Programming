#include <bits/stdc++.h>
using namespace std;
const int kN = 2e5 + 10;
const int kMod = 998244353;

int n, k;
int p[kN];
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
	vector<int> pos;
	for(int i = 1; i <= n; i++)
		if(p[i] >= n - k + 1) pos.push_back(i);

	long long sum = 0;
	for(int i = n - k + 1; i <= n; i++) sum += i;

	int ans = 1;
	for(int i = 0; i < k - 1; i++) ans = 1LL * ans * (pos[i + 1] - pos[i]) % kMod;
	printf("%lld %d\n", sum, ans);
	return 0;
}
