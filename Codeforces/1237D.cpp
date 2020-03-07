#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int INF = 1e9;
int a[maxn];
int n;
int sp[20][maxn];
int lg[maxn];
int nxt[maxn];
int ans[maxn];
int query(int l, int r) {
	int len = r - l + 1;
	int j = lg[len];
	return min(sp[j][l], sp[j][r - (1 << j) + 1]);
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	int mi = INF, mx = -INF;
	for(int i = 0; i < n; i++) mi = min(mi, a[i]), mx = max(mx, a[i]);
	if(mi * 2 >= mx) {
		for(int i = 0; i < n; i++) printf("-1 "); puts("");
		return 0;
	}
	for(int i = n; i < 3 * n; i++) a[i] = a[i - n];
	for(int i = 2; i < 3 * n; i++) lg[i] = lg[i >> 1] + 1;
	for(int i = 0; i < 3 * n; i++) sp[0][i] = a[i];
	for(int j = 1; j <= 18; j++) 
		for(int i = 0; i < 3 * n; i++) sp[j][i] = min(sp[j - 1][i], sp[j - 1][i + (1 << (j - 1))]);
	for(int i = 0; i < 2 * n; i++) {
		if(query(i + 1, i + n - 1) * 2 >= a[i]) {
			nxt[i] = INF; continue;
		}
		int l = i + 1, r = i + n;
		while(l != r) {
			int m = (l + r) >> 1;
			if(query(i + 1, m) * 2 >= a[i]) l = m + 1;
			else r = m;
		}
		nxt[i] = l;
	}
	//for(int i = 0; i < n; i++) printf("%d ", nxt[i]); puts("");
	deque<int> dq;
	for(int i = 0; i < n; i++) {
		while(!dq.empty() && nxt[dq.back()] >= nxt[i]) dq.pop_back();
		dq.push_back(i);
	}
	for(int i = n; i < 2 * n; i++) {
		while(!dq.empty() && dq.front() < i - n) dq.pop_front();
		while(!dq.empty() && nxt[dq.back()] >= nxt[i]) dq.pop_back();
		dq.push_back(i);
		ans[i - n] = nxt[dq.front()] - (i - n);
	}
	for(int i = 0; i < n; i++) printf("%d ", ans[i]); puts("");
	return 0;
}
