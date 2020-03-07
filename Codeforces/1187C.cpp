#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m;
int t[maxn], l[maxn], r[maxn];
int a[maxn];
bool is[maxn];
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &t[i], &l[i], &r[i]);
		if(t[i]) {
			for(int j = l[i]; j < r[i]; j++) is[j] = 1;
		}
	}
	a[1] = (int)1e9;
	for(int i = 1; i < n; i++) {
		if(is[i]) a[i + 1] = a[i];
		else  a[i + 1] = a[i] - 1;
	}
	for(int i = 1; i <= m; i++) {
		if(!t[i]) {
			bool flag = 0;
			for(int j = l[i]; j < r[i]; j++) 
				if(a[j] > a[j + 1]) flag = 1;
			if(!flag) return 0 * puts("NO");
		}
	}
	puts("YES");
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}
