#include <bits/stdc++.h>
using namespace std;
int cal(int x) {
	int res = x;
	while(x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}
int main() {
	int n; scanf("%d", &n);
	vector<int> v;
	for(int i = n - 100; i <= n; i++) {
		if(cal(i) == n) v.push_back(i);
	}
	printf("%d\n", int(v.size()));
	for(int x : v) printf("%d ", x); puts("");
	return 0;
}
