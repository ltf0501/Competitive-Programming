#include <bits/stdc++.h>
using namespace std;
const int kN = 3e5 + 10;
int n;
int a[kN], b[kN];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", a + i, b + i);

	int x = 0, y = 0;
	vector<int> X, Y;
	for(int i = 1; i <= n; i++) {
		if(a[i] < b[i]) x++, X.push_back(i);
		else y++, Y.push_back(i);
	}

	printf("%d\n", max(x, y));
	if(x > y) {
		sort(X.begin(), X.end(), [&](int i, int j) {return a[i] > a[j];});
		for(int i : X) printf("%d ", i); puts("");
	}
	else {
		sort(Y.begin(), Y.end(), [&](int i, int j) {return b[i] < b[j];});
		for(int i : Y) printf("%d ", i); puts("");
	}
	return 0;
}
