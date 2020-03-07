#include <bits/stdc++.h>
using namespace std;
const int mod[] = {(int)1e9 + 7, (int)1e9 + 9, (int)1e9 + 123};
vector<string> c;
vector<vector<int>> dp[3], dp2[3];
void add(int& a, int b, int mod) {
	a += b;
	if(a >= mod) a -= mod;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	c.resize(n);
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < 3; i++) dp[i].resize(n), dp2[i].resize(n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) dp[j][i].resize(m, 0), dp2[j][i].resize(m, 0);
	}
	for(int i = 0; i < 3; i++) dp[i][0][0] = 1, dp2[i][n - 1][m - 1] = 1;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(c[i][j] != '#') {
		for(int k = 0; k < 3; k++) {
			if(i) add(dp[k][i][j], dp[k][i - 1][j], mod[k]);
			if(j) add(dp[k][i][j], dp[k][i][j - 1], mod[k]);
		}
	}

	for(int i = n - 1; i >= 0; i--) for(int j = m - 1; j >= 0; j--) if(c[i][j] != '#') {
		for(int k = 0; k < 3; k++) {
			if(i < n - 1) add(dp2[k][i][j], dp2[k][i + 1][j], mod[k]);
			if(j < m - 1) add(dp2[k][i][j], dp2[k][i][j + 1], mod[k]);
		}
	}

	if(dp[0][n - 1][m - 1] == 0 && dp[1][n - 1][m - 1] == 0 && dp[2][n - 1][m - 1] == 0) 
		return cout << 0 << '\n', 0;
/*	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) cout << dp[0][i][j] << ' '; cout << '\n';
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) cout << dp2[0][i][j] << ' '; cout << '\n';
	}
*/
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(c[i][j] != '#') {
		if(i == 0 && j == 0) continue;
		if(i == n - 1 && j == m - 1) continue;

		bool flag = 1;
		for(int k = 0; k < 3; k++) {
			if(1LL * dp[k][i][j] * dp2[k][i][j] % mod[k] != dp[k][n - 1][m - 1]) flag = 0;
		}
		if(flag) return cout << 1 << '\n', 0;
	}
	cout << 2 << '\n';
	return 0;
}
