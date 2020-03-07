#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v[305];
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) v[i].push_back(j * n + i);
	}
	for(int i = 0; i < n / 2; i ++) {
		for(int j = 1; j < n; j += 2) swap(v[i][j], v[n - 1 - i][j]);
	}
	for(int i = 0; i < n; i++) {
		for(int x : v[i]) printf("%d ", x + 1); puts("");
	}
	return 0;
}
