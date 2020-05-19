#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, s; scanf("%d%d", &n, &s);
	if(s >= 2 * n) {
		puts("YES");
		for(int i = 1; i < n; i++) printf("2 ");
		printf("%d\n1", s - 2 * (n - 1)); 
	}
	else puts("NO");
	return 0;
}
