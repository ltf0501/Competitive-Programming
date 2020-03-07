#include <bits/stdc++.h>
using namespace std;
const int kN = 1e6 + 10;
int n;
int cnt[kN];
int pre[kN];
vector<int> tmp;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i : tmp) cnt[i] = 0;	
		tmp.clear();
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			cnt[x]++;
			tmp.push_back(x);
		}
		sort(tmp.begin(), tmp.end(), greater<int>());
		tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
		//for(int x : tmp) printf("%d ", x); puts("");
		vector<int> v;
		for(int x : tmp) v.push_back(cnt[x]);

		int m = int(v.size());
		int g = v[0];
		int res[2] = {0, 0};
		int id = 0;
		int cur = 1;
		for(int i = 1; i <= m; i++) {
			pre[i] = pre[i - 1] + v[i - 1];
			if(id < 2 && pre[i] - pre[cur] > g) {
				res[id++] = pre[i] - pre[cur];
				cur = i;
				//printf("i = %d\n", i);
			}
		}
		//for(int i = 1; i <= m; i++) 
		//	printf("%d ", pre[i]);
		//puts("");
		int tot = n / 2;
		int k = upper_bound(pre + 1, pre + m + 1, tot) - pre - 1;
		//printf("k = %d\n", k);

		if(id < 2 || cur > k) puts("0 0 0");
		else {
			res[1] = pre[k] - g - res[0];
			printf("%d %d %d\n", g, res[0], res[1]); 
		}
	}

	return 0;
}
