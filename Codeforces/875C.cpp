#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10;

int n, m;
vector<int> v[kN];
int ans[kN];
vector<int> g[kN];

void bye() {
	puts("No");
	exit(0);
}

void dfs(int u) {
	for(int v : g[u]) {
		if(ans[v] == -1) bye();
		else if(!ans[v]) {
			ans[v] = 1;
			dfs(v);
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		int num; scanf("%d", &num);
		v[i].resize(num);
		for(int j = 0; j < num; j++) scanf("%d", &v[i][j]);
	}

	bool flag = 1;
	for(int i = 1; i < n; i++) {
		//printf("i = %d\n", i);
		int j = 0;
		while(j < v[i].size() && j < v[i + 1].size() && v[i][j] == v[i + 1][j]) j++;
		if(j == v[i].size() || j == v[i + 1].size()) {
			if(v[i].size() > v[i + 1].size()) bye();
			else continue;
		}
		//printf("j = %d\n", j);
		
		if(v[i][j] < v[i + 1][j]) {
			g[v[i + 1][j]].push_back(v[i][j]);
		}
		else {
			if(ans[v[i][j]] == -1 || ans[v[i + 1][j]] == 1) bye();
			ans[v[i][j]] = 1, ans[v[i + 1][j]] = -1;
		}
	}
	
	for(int i = 1; i <= m; i++) {
		if(ans[i] == 1) dfs(i);
	}
	
	puts("Yes");
	int cnt = 0;
	for(int i = 1; i <= m; i++)
		if(ans[i] == 1) cnt++;
	printf("%d\n", cnt);
	for(int i = 1; i <= m; i++)
		if(ans[i] == 1) printf("%d ", i);
	puts("");
	return 0;
}
