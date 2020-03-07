#include <bits/stdc++.h>
using namespace std;
const int kN = 2e4 + 10;
int n, m, k;
int dp[55][kN], premax[55][kN], sufmax[55][kN];
int a[55][kN], pre[55][kN];
int Area(int x, int l, int r) {return pre[x][r] - pre[x][l];} // (l, r]
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) scanf("%d", &a[i][j]);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) pre[i][j] = pre[i][j - 1] + a[i][j];

	for(int i = 1; i <= n; i++) {
		for(int j = k; j <= m; j++) {
			int area = Area(i, j - k, j) + Area(i + 1, j - k, j);
			dp[i][j] = max(dp[i][j], premax[i - 1][j - k] + area);
			if(j + k <= m) dp[i][j] = max(dp[i][j], sufmax[i - 1][j + k] + area);
		}

		deque<int> dq;
		for(int j = 1; j < k; j++) dq.push_back(j);
		for(int j = k; j <= m; j++) {
			while(!dq.empty() && j - dq.front() >= k) dq.pop_front();
			
			while(!dq.empty() && dp[i - 1][j] - Area(i, dq.back(), j) >= dp[i - 1][dq.back()]) dq.pop_back();
			dq.push_back(j);
			int x = dq.front();
			int area = Area(i, j - k, j) + Area(i + 1, j - k, j);
			dp[i][j] = max(dp[i][j], dp[i - 1][x] + area - Area(i, j - k, x));
		}
		dq.clear();
		for(int j = m; j >= k; j--) {
			while(!dq.empty() && dq.front() - j >= k) dq.pop_front();

			while(!dq.empty() && dp[i - 1][j] - Area(i, j - k, dq.back() - k) >= dp[i - 1][dq.back()]) dq.pop_back();
			dq.push_back(j);
			int x = dq.front();
			int area = Area(i, j - k, j) + Area(i + 1, j - k, j);
			dp[i][j] = max(dp[i][j], dp[i - 1][x] + area - Area(i, x - k, j));
		}

		for(int j = 1; j <= m; j++) premax[i][j] = max(premax[i][j - 1], dp[i][j]);
		for(int j = m; j >= 1; j--) sufmax[i][j] = max(sufmax[i][j + 1], dp[i][j]);
	}

	int ans = 0;
	for(int i = 1; i <= m; i++) ans = max(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}
