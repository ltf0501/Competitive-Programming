#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[2001];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int x;
		scanf("%d", &x);
		int n = 1;
		while((ll)n * (n + 1) * (n + 2) / 6 <= x) n++;
		n--;
		int N = n;
		for(int i = 1; i <= n; i++) cnt[i] = 1;
		x -= (ll)n * (n + 1) * (n + 2) / 6;
		while(x) {
			while((ll)n * (n + 1) / 2 > x) n--;
			cnt[n]++, x -= (ll)n * (n + 1) / 2;
		}
		putchar('1');
		for(int i = 1; i <= N; i++) {
			if(i == 1) putchar('3');
			putchar('3');
			for(int j = 1; j <= cnt[i]; j++) putchar('7');
		}
		puts("");
	}
	return 0;
}
