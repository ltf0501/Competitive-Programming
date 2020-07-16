#include <bits/stdc++.h>
using namespace std;
const int kN = 1e3 + 10;

int a[kN];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		vector<int> ans;
		while(true) {
			int id = -1;
			vector<int> vis(n + 1, 0);
			for(int i = 0; i < n; i++) {
				if(a[i] != i) id = i;
				vis[a[i]] = 1;
			}
			if(id == -1) break;
			int mex = n;
			for(int i = 0; i < n; i++)
				if(!vis[i]) {mex = i; break;}

			if(mex == n) {
				ans.push_back(id);
				a[id] = mex;
			}
			else {
				ans.push_back(mex);
				a[mex] = mex;
			}
		}

		printf("%d\n", int(ans.size()));
		for(int x : ans) printf("%d ", x + 1); puts("");
		for(int i = 0; i < n; i++) assert(a[i] == i);
	}
	return 0;
}
