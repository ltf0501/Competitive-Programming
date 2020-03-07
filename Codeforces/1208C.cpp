#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int base[4][4] = {{0, 1, 4, 5}, {2, 3, 6, 7}, {8, 9, 12, 13}, {10, 11,14, 15}};
int p[maxn][maxn];
int n;
int main() {
	scanf("%d", &n);
	int m = n / 4;
	for(int i = 0; i < m; i++) for(int j = 0; j < m; j++) {
		for(int a = 0; a < 4; a++) for(int b = 0; b < 4; b++)
			p[i * 4 + a][j * 4 + b] = 16 * (i * m + j) + base[a][b];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) printf("%d ", p[i][j]); puts("");
	}
	return 0;
}

