#include <bits/stdc++.h>
using namespace std;
void f(int n, char a, char b, char c) {
	if(n == 1) {
		printf("Move ring %d from %c to %c\n", n, a, c);
		return;
	}
	f(n - 1, a, c, b);
	printf("Move ring %d from %c to %c\n", n, a, c);
	f(n - 1, b, a, c); 
}
int main() {
	int n;
	while(~scanf("%d", &n)) {
		f(n, 'A', 'B', 'C');
	}
	return 0;
}
