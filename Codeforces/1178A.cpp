#include <bits/stdc++.h>
using namespace std;
const int kN = 105;
int n;
int a[kN];
int main() {
	scanf("%d", &n);
	int sum = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
	int tot = a[1];
	vector<int> v;
	v.push_back(1);
	for(int i = 2; i <= n; i++) if(a[i] * 2 <= a[1]) {
		v.push_back(i);
		tot += a[i];
	}
	if(tot * 2 > sum) {
		printf("%d\n", int(v.size()));
		for(int x : v) printf("%d ", x); puts("");
	}
	else puts("0");
	return 0;
}
