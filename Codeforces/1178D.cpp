#include <bits/stdc++.h>
using namespace std;
const int kN = 1e3 + 10;
int pr[10000];
int main() {
	for(int i = 2; i < 10000; i++) {
		int j;
		for(j = 2; j * j <= i; j++) if(i % j == 0) break;
		if(j * j > i) pr[i] = 1;
	}
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> ans;
	for(int i = 0; i < n; i++) ans.emplace_back(i, (i + 1) % n);
	int now = n;
	int l = 0, r = n / 2;
	while(!pr[now]) {
		ans.emplace_back(l++, r++);
		now++;
	}
	printf("%d\n", int(ans.size()));
	for(auto p : ans) printf("%d %d\n", p.first + 1, p.second + 1);
	return 0;
}
