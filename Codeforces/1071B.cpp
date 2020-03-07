#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 10;
const int INF = 1e9;
typedef pair<int, int> pii;
#define F first
#define S second
int n, k;
char c[maxn][maxn];
int dp[maxn][maxn];
bool is[maxn][maxn];
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%s", c[i]);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			dp[i][j] = INF;
			if(i == 0 && j == 0) dp[i][j] = 0;
			if(i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
			dp[i][j] += c[i][j] != 'a';
		}
	}
	int mx = -1;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) 
		if(dp[i][j] <= k && mx < i + j) mx = i + j;
	//printf("mx = %d\n", mx);
	vector<char> ans;
	for(int i = 0; i <= mx; i++) ans.push_back('a');
	vector<pii> v;
	if(mx >= 0) {
		for(int i = 0; i < n; i++) {
			int j = mx - i;
			if(j >= 0 && j < n && dp[i][j] == k) v.push_back({i, j});  
		}
	}
	else ans.push_back(c[0][0]), mx = 0, v.push_back({0, 0});
	for(int cur = mx; cur < (n - 1) + (n - 1); cur++) {
		vector<pii> tmp;
		int now_mi = INF;
		for(auto p : v) {
			int x = p.F, y = p.S;
			if(x + 1 < n) {
				if(c[x + 1][y] - 'a' < now_mi) {
					tmp.clear();
					tmp.push_back({x + 1, y});
					now_mi = c[x + 1][y] - 'a';
				}
				else if(c[x + 1][y] - 'a' == now_mi) tmp.push_back({x + 1, y});
			}
			if(y + 1 < n) {
				if(c[x][y + 1] - 'a' < now_mi) {
					tmp.clear();
					tmp.push_back({x, y + 1});
					now_mi = c[x][y + 1] - 'a';
				}
				else if(c[x][y + 1] - 'a' == now_mi) tmp.push_back({x, y + 1});
			}
		}
		ans.push_back(now_mi + 'a');
		v.clear();
		for(auto p : tmp) is[p.F][p.S] = 1;
		for(int i = 0; i < n; i++) {
			int j = cur + 1 - i;
			if(j >= 0 && j < n && is[i][j]) v.push_back({i, j});
		}
	}
	for(char c : ans) putchar(c); puts("");
	return 0;
}
