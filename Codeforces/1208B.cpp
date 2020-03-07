#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
#define ALL(v) v.begin(), v.end()
int n;
int a[maxn];
int cnt[maxn], cnt2[maxn];
vector<int> v;
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), v.push_back(a[i]);
	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());
	for(int i = 1; i <= n; i++) a[i] = lower_bound(ALL(v), a[i]) - v.begin() + 1;
	for(int i = 1; i <= n; i++) cnt[a[i]]++;
	for(int i = 1; i < maxn; i++) cnt2[i] = cnt[i];
	int num = 0;
	for(int i = 1; i < maxn; i++) if(cnt[i] >= 2) num++;
	if(num == 0) return 0 * puts("0");
	int ans = n - 1;
	for(int i = 1; i <= n; i++) {
		for(int k = 1; k < maxn; k++) cnt[k] = cnt2[k];
		int nnum = num;
		for(int j = i; j <= n; j++) {
			cnt[a[j]]--;
			if(cnt[a[j]] == 1) nnum--;
			if(nnum == 0) {
				ans = min(ans, j - i + 1);
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

