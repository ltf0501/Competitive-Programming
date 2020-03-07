#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long ll;
int n, w;
int sz[maxn];
vector<int> v[maxn];
vector<int> pre[maxn], suf[maxn];
int mx[maxn];
ll b[maxn];
int main() {
	scanf("%d%d", &n, &w);
	for(int i = 1; i <= n; i++) {
//		printf("%d\n", sz[i]);
		scanf("%d", &sz[i]);
		v[i].resize(sz[i] + 5, 0);
		pre[i].resize(sz[i] + 5, 0), suf[i].resize(sz[i] + 5, 0);
		for(int j = 1; j <= sz[i]; j++) {
			scanf("%d", &v[i][j]);
		}
		for(int j = 1; j <= sz[i]; j++) pre[i][j] = max(pre[i][j - 1], v[i][j]), mx[i] = max(mx[i], v[i][j]);
		for(int j = sz[i]; j >= 1; j--) suf[i][j] = max(suf[i][j + 1], v[i][j]);
	}
	/*
	for(int i = 1; i <= n; i++) {
		printf("pre: "); for(int j = 1; j <= sz[i]; j++) printf("%d ", pre[i][j]); puts("");
		printf("suf: "); for(int j = 1; j <= sz[i]; j++) printf("%d ", suf[i][j]); puts("");
	}
	*/
	for(int i = 1; i <= n; i++) {
		if(sz[i] * 2 > w) {
			deque<int> dq;
			dq.push_back(0);
			for(int j = 1; j <= w; j++) {
				while(!dq.empty() && j - dq.front() > w - sz[i]) dq.pop_front();
				if(j <= sz[i] + 1) {
					while(!dq.empty() && v[i][j] >= v[i][dq.back()]) dq.pop_back();
					dq.push_back(j);
				}//j th += max
				b[j] += v[i][dq.front()], b[j + 1] -= v[i][dq.front()];
			}
		}
		else {
			for(int j = 1; j <= sz[i]; j++) b[j] += pre[i][j], b[j + 1] -= pre[i][j];
			for(int j = w; j >= w - sz[i] + 1; j--) b[j] += suf[i][j + sz[i] - w], b[j + 1] -= suf[i][j + sz[i] - w];
			b[sz[i] + 1] += mx[i], b[w - sz[i] + 1] -= mx[i];
		}
	}
	for(int i = 2; i <= w; i++) b[i] += b[i - 1];
	for(int i = 1; i <= w; i++) printf("%lld ", b[i]); puts("");
	return 0;
}
