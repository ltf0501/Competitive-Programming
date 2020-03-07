#include <cstdio>
using namespace std;
int cnt = 0;
int f(int n) {
	cnt++;
	if(n == 0) return 0;
	if(n == 1) return 1;
	return f(n - 1) + f(n - 2);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", f(n));
	printf("%c%d\n", cnt == 0 ? '\n' : ' ', cnt);
	return 0;
}
