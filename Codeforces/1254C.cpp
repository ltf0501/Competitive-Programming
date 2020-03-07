#include <bits/stdc++.h>
using namespace std; 
const int maxn = 1e3 + 10;
typedef long long ll;
typedef pair<int, int> pii;
#define F first
#define S second
int n;
ll area[maxn];
vector<int> L, R;
ll query(int type, int a, int b, int c) {
	printf("%d %d %d %d\n", type, a, b, c);
	fflush(stdout);
	ll x;
	scanf("%lld", &x);
	return x;
}
bool cmp(int i, int j) {
	return area[i] > area[j];
}
vector<int> gao(vector<int> v, int a, int b) {
	if(v.empty()) return v;

	vector<int> res1, res2;
	sort(v.begin(), v.end(), cmp);
	int idx = v[0];
	for(int i = 1; i < int(v.size()); i++) {
		if(query(2, b, idx, v[i]) < 0) res1.push_back(v[i]);
		else res2.push_back(v[i]);
	}
	reverse(res1.begin(), res1.end());
	res1.push_back(idx);
	for(int x : res2) res1.push_back(x);
	return res1;
}
int main() {
	scanf("%d", &n);
	for(int i = 3; i <= n; i++) {
		area[i] = query(1, 1, 2, i);
		int t = query(2, 1, 2, i);
		if(t > 0) L.push_back(i);
		else R.push_back(i);
	}
	L = gao(L, 1, 2);
	R = gao(R, 2, 1);
	printf("0 1 ");
	for(int x : R) printf("%d ", x);
	printf("2 ");
	for(int x : L) printf("%d ", x);
	puts("");
	fflush(stdout);
	return 0;
}
