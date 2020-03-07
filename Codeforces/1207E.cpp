#include <bits/stdc++.h>
using namespace std;
#define umr fflush(stdout)
int main() {
	printf("? ");
	for(int i = 1; i <= 100; i++) printf(" %d",i); puts("");
	umr;
	int a;
	scanf("%d", &a);
	printf("? ");
	for(int i = 1; i <= 100; i++) printf(" %d", i << 7); puts("");
	umr;
	int b;
	scanf("%d", &b);
	printf("! %d\n", (a & (127 << 7)) + (b & 127));
	return 0;
}
