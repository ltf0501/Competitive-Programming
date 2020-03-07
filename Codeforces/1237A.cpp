#include <bits/stdc++.h>
using namespace std;
const int maxn = 20010;
int a[maxn];
int b[maxn];
vector<int> v;
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if(a[i] & 1) v.push_back(i);
	}
	//for(int x : v) printf("%d ", x); puts("");
	for(int i = 0; i < int(v.size()) / 2; i++) b[v[i]] = 1;
	for(int i = int(v.size()) / 2; i < int(v.size()); i++) b[v[i]] = -1;
	for(int i = 0; i < n; i++) {
		if(a[i] & 1) {
			if(b[i] == 1) b[i] = (a[i] + 1) / 2;
			else b[i] = (a[i] - 1) / 2;
		}
		else {
			b[i] = a[i] / 2;
		}
	}
	for(int i = 0; i < n; i++) printf("%d\n", b[i]);
	return 0;
}
