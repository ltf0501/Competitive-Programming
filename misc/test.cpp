#include<bits/stdc++.h>
using namespace std;
int a[500];
main()
{
	int n = 500;
	int k = 303;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> dis(0, (int)1e9);
	for(int i = 0; i < n; i++) {
		a[i] = i * 211243 + 10; 
	}
	sort(a, a + n);
	printf("%d %d\n", n, k);
	for(int i = 0; i < n; i++) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
    return 0;
}
