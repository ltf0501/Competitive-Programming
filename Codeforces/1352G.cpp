#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		if(n <= 3) {
			puts("-1");
			continue;
		}
		vector<int> v1, v2;
		for(int i = 1; i <= n; i += 2) v1.push_back(i);
		for(int i = 2; i <= n; i += 2) v2.push_back(i);
		reverse(v2.begin(), v2.end());
		v2.pop_back();
		v2.pop_back();
		v2.push_back(2), v2.push_back(4);
		for(int x : v2) printf("%d ", x);
		for(int x : v1) printf("%d ", x);
		puts("");
	} 
	return 0;
}
