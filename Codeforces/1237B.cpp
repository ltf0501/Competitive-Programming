#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], b[maxn];
int out[maxn];
bool check[maxn];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	int ans = 0;
	for(int i = n, j = n; i >= 1; i--) {
		while(j && check[b[j]]) j--;
		if(a[i] != b[j]) ans++;
		check[a[i]] = 1;
	}
	printf("%d\n", ans);
	return 0;
}

