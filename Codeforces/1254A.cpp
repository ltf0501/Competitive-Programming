#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
char c[maxn][maxn];
char ans[maxn][maxn];
int n, m, k;
char get_char(int id) {
	if(id < 26) return 'a' + id;
	if(id < 52) return 'A' + id - 26;
	return '0' + id - 52;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 0; i < n; i++) scanf("%s", c[i]);
		int cnt = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) cnt += (c[i][j] == 'R');
		int t = cnt / k;
		int r = cnt % k;
		int cur = 0;
		int now = r ? t + 1 : t;
		if(r) r--;
		for(int i = 0; i < n; i++) {
			if(i % 2 == 0) {
				for(int j = 0; j < m; j++) {
					ans[i][j] = get_char(cur);
					if(c[i][j] == 'R') {
						now--;
						if(cur + 1 < k && now == 0) {
							cur++;
							if(r) now = t + 1, r--;
							else now = t;
						}
					}
				}
			}
			else {
				for(int j = m - 1; j >= 0; j--) {
					ans[i][j] = get_char(cur);
					if(c[i][j] == 'R') {
						now--;
						if(cur + 1 < k && now == 0) {
							cur++;
							if(r) now = t + 1, r--;
							else now = t;
						}
					}
				}

			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) putchar(ans[i][j]);
			puts("");
		}
	}
	return 0;
}

