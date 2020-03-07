#include <bits/stdc++.h>
using namespace std;
const int kN = 1e6 + 10;
int a[kN];
bool vis[kN];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) vis[i] = 0;
		for(int i = 1; i <= n; i++) {
			int x;
			scanf("%d", &x);
			a[i] = i - x;
		}
		vector<int> v;
		int now = 1;
		do {
			vis[now] = 1;
			now = a[now];
		} while(!vis[now]);
		int Now = now;
		do {
			v.push_back(Now);
			Now = a[Now];
		} while(Now != now);
		printf("%d\n", int(v.size()));
		for(int x : v) printf("%d ", x); puts("");
	}
	return 0;
}
