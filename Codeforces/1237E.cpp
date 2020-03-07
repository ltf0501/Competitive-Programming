#include <bits/stdc++.h>
using namespace std;
int sol(int x) {
	int now[] = {1, 2};
	bool flag = 0;
	while(now[1] < x) {
		if(!flag) now[0] = now[1] * 2;
		else now[0] = now[0] * 2 + 1;
		now[1] = now[0] + 1;
		flag ^= 1;
		//printf("now[0] = %d, now[1] = %d\n", now[0], now[1]);
	}
	return x == now[0] || x == now[1];
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", sol(n));
	return 0;
}
