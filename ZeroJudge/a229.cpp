#include <bits/stdc++.h>
using namespace std;
char ans[30];
int n;
void dfs(int now, int k) {
	if(2 * n - now < k) return;
	if(now == 2 * n) {
		if(k != 0) return;
		for(int i = 0; i < 2 * n; i++) putchar(ans[i]);
		puts("");
		return;
	}
	ans[now] = '(';
	dfs(now + 1, k + 1);
	if(k) {
		ans[now] = ')';
		dfs(now + 1, k - 1);
	}
}
int main() {
	while(~scanf("%d", &n)) 
		dfs(0, 0);
	return 0;
}
