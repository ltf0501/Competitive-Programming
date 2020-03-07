#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
typedef pair<int, int> pii;
#define F first
#define S second
int d[maxn];
vector<int> v[maxn];
pii a[maxn];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &d[i]);
	for(int i = 1; i <= n; i++) a[i] = make_pair(i, d[i]);
	sort(a + 1, a + n + 1, [](pii x, pii y){return x.S > y.S;});
	for(int i = 1; i <= n; i++) {
		a[i].F = 2 * a[i].F - 1;
		v[i].push_back(a[i].F);
	}
	//for(int i = 1; i <= n; i++) printf("%d ", a[i].F); puts("");
	vector<pair<int, int>> ans;
	for(int i = 2; i <= n; i++) ans.emplace_back(a[i].F, a[i - 1].F);
	for(int i = 1; i <= n; i++) {
		int now = i + a[i].S - 1;
		ans.emplace_back(a[i].F + 1, v[now][0]);
		v[now + 1].push_back(a[i].F + 1);
	}
	for(auto x : ans) printf("%d %d\n", x.first, x.second);
	return 0;
}
