#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10;

int n;
int s, t;
int x[kN];
bool Check(int d) {
	set<int> st;
	st.insert(s), st.insert(t);
	for(int i = 1; i <= n; i++) {
		while(!st.empty() && abs(*(st.begin()) - x[i]) > d) st.erase(st.begin());
		while(!st.empty() && abs(*(prev(st.end())) - x[i]) > d) st.erase(prev(st.end()));
		if(st.empty()) return 0;
		st.insert(x[i]);
	}
	return 1;
}
int main() {
	scanf("%d%d%d", &n, &s, &t);
	for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
	int l = abs(s - t), r = 1e9 + 1;
	while(l != r) {
		int m = (l + r) >> 1;
		if(Check(m)) r = m;
		else l = m + 1;
	}
	printf("%d\n", l);
	return 0;
}
