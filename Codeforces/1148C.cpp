#include <bits/stdc++.h>
using namespace std;
const int kN = 3e5 + 10;
typedef pair<int, int> pii;
#define F first
#define S second
int n;
int p[kN], r[kN];
vector<pii> ans;
void change(int x, int y) {
	if(x == y) return;
	ans.emplace_back(x, y);
	int a = p[x], b = p[y];
	swap(r[a], r[b]);
	swap(p[x], p[y]);
}
void print() {
	printf("%d\n", int(ans.size()));
	for(auto p : ans) printf("%d %d\n", p.F + 1, p.S + 1);
	//for(int i = 0; i < n; i++) printf("%d ", p[i] + 1); puts("");
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", p + i), p[i]--, r[p[i]] = i;
	for(int i = 0; i < n / 2; i++) {
		if(r[i] == i) continue;
		if(r[i] < n / 2) {
			change(r[i], n - 1), change(n - 1, i);	
		}
		else if(r[i] < n / 2 + i) {
			int pos = r[i];
			change(0, r[i]), change(0, n - 1), change(n - 1, i), change(0, pos);
		}
		else change(i, r[i]);
	}
	for(int i = n / 2; i < n; i++) {
		int pos = r[i];
		if(pos == i) continue;
		change(0, r[i]), change(0, i), change(0, pos);
	}
	print();
	return 0;
}
