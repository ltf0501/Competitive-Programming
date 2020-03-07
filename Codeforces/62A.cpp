#include <bits/stdc++.h>
using namespace std;
bool check(int x, int y) {
	if(y < x - 1 || y > 2 * (x + 1)) return 0;
	return 1;
}
int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if(check(a, d) || check(b, c)) puts("YES");
	else puts("NO");
	return 0;
}
