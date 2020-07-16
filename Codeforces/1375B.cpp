#include <bits/stdc++.h>
using namespace std;
const int kN = 305;

int n, m;
int a[kN][kN];
int Num(int x, int y) {
	return (x > 0) + (x < n - 1) + (y > 0) + (y < m - 1);
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) scanf("%d", &a[i][j]);

		bool flag = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) flag &= a[i][j] <= Num(i, j);

		if(!flag) puts("NO");
		else {
			puts("YES");
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) printf("%d ", Num(i, j)); puts("");
			}
		}
	}
	return 0;
}
