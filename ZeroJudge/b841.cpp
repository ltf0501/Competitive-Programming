#include <stdio.h>

int n, m;
int a[10][10];
bool vis[10][10];
int ans;
int max(int x, int y) {
	if(x >= y) return x;
	return y;
}
void dfs(int i, int j, int cnt) {
	if(i == n - 1 && j == m - 1) {
		ans = max(ans, cnt);
		return;
	}
	if(!vis[i][j]) {
		if(j != m - 1 && !vis[i][j + 1] && a[i][j] == a[i][j + 1]) {
			vis[i][j + 1] = 1;
			dfs(i, j + 1, cnt + 1);
			vis[i][j + 1] = 0;
		}
		if(i != n - 1 && !vis[i + 1][j] && a[i][j] == a[i + 1][j]) {
			vis[i + 1][j] = 1;
			if(j != m - 1) dfs(i, j + 1, cnt + 1);
			else dfs(i + 1, 0, cnt + 1);
			vis[i + 1][j] = 0;
		}
	}
	if(j != m - 1) dfs(i, j + 1, cnt);
	else dfs(i + 1, 0, cnt);
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) scanf("%d", &a[i][j]);
	dfs(0, 0, 0);
	printf("%d\n", ans);
	return 0;
}
