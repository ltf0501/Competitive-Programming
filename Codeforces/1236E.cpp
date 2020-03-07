#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
vector<int> v[maxn];
int pre[maxn], suf[maxn];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int x;
		scanf("%d", &x);
		v[x].push_back(i);
	}
	int now = 0;
	for(int x = n; x >= 1; x--) {
		sud[x] = max(m - now, n - x);
		bool flag = 1;
		for(int i : v[x]) 
			if(i ==  
	}
	return 0;
}
