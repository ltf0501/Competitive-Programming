#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
const int maxT = 1e2 + 10;
vector<int> v[maxT];

int main() {
	int n, T;
	scanf("%d%d", &n, &T);
	for(int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	for(int i = 1; i < T; i++) {
		sort(v[i].begin(), v[i].end(), [](int a, int b) {return a > b;});
		for(int j = 0; j < (int)v[i].size() - 1; j += 2) v[i + 1].push_back(v[i][j] + v[i][j + 1]);
		if(int(v[i].size()) & 1) v[i + 1].push_back(v[i].back());
	}
	int ans = 0;
	for(int x : v[T]) ans = max(ans, x);
	printf("%d\n", ans);
	return 0;
}
