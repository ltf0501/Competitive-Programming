#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		vector<int> ans;
		int cur = 1;
		for(int i = 0; i < 5; i++) {
			if(n % 10 != 0) ans.push_back((n % 10) * cur);
			cur *= 10;
			n /= 10;
		}
		printf("%d\n", ans.size());
		for(int x : ans) printf("%d ", x); puts("");
	}
	return 0;
}
