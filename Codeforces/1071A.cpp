#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int k;
	for(int i = 1;; i++) 
		if(1LL * i * (i + 1) / 2 > n + m) {k = i - 1; break;}
	vector<int> A, B;
	for(int i = k; i >= 1; i--) {
		if(n >= i) A.push_back(i), n -= i;
		else B.push_back(i), m -= i;
	}
	printf("%d\n", (int)A.size());
	for(int x : A) printf("%d ", x); puts("");
	printf("%d\n", (int)B.size());
	for(int x : B) printf("%d ", x); puts("");
	return 0;
}
