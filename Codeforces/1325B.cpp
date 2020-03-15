#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		set<int> s;
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			s.insert(x);
		}
		printf("%d\n", int(s.size()));
	}
	return 0;
}
