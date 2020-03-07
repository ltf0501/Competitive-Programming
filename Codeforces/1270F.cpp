#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kN = 2e5 + 10;
const int kB = 500;
char c[kN];
int pre[kN];
int cnt[kN * kB];
int main() {
	scanf("%s", c + 1);
	int n = strlen(c + 1);
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (c[i] - '0');
	//int B = 300;
	int B = int(sqrt(n + 0.5));
	int x = n / B;
	//printf("B = %d, x = %d\n", B, x);
	ll ans = 0;
	for(int k = 1; k <= B; k++) {
		for(int i = 0; i <= n; i++) ans += cnt[i - k * pre[i] + n * B]++;
		for(int i = 0; i <= n; i++) cnt[i - k * pre[i] + n * B]--;
	}

	vector<int> pos;
	for(int i = 1; i <= n; i++) 
		if(c[i] == '1') pos.push_back(i);
	//for(int x : pos) printf("%d ", x); puts("");
	pos.push_back(n + 1);
	int m = int(pos.size());
	for(int l = 0, l_id = 0; l < n; l++) {
		if(l == pos[l_id]) l_id++;	
		for(int j = 1; j <= x && l_id + j < m; j++) {
			int r_mx = pos[l_id + j] - 1;
			int r_mn = pos[l_id + j - 1] - 1;
			int tmp;
			ans += tmp = max(0, (r_mx - l) / j - max(B, (r_mn - l) / j)); 
			//printf("l = %d, j = %d, r_mx = %d, r_mn = %d, cnt = %d\n", l, j, r_mx, r_mn, tmp);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
// 00001100000000000000
