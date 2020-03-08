#include <bits/stdc++.h>
using namespace std;
const int kN = 4e5 + 10;

int n;
int a[kN], b[kN];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	int ans = 0;
	for(int r = 1; r < (int)2e7; r <<= 1) {
		for(int i = 1; i <= n; i++) b[i] = a[i] & (r - 1);
		int tot = 0;
		for(int i = 1; i <= n; i++)
			if(a[i] & r) tot++;
		if((tot & 1) && ((n - 1) & 1)) ans ^= r;

		sort(b + 1, b + n + 1);

		tot = 0;
		for(int i = 1, j = n; i <= n; i++) {
			j = max(i, j);
			while(i < j && b[i] + b[j] >= r) j--;
			tot += n - j;
		}

		if(tot & 1) ans ^= r;
	}
	printf("%d\n", ans);
	return 0;
}
