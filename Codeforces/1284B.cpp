#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10;
const int kInf = 1e9 + 10;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> mn, mx;
	for(int i = 0; i < n; i++) {
		int mxval = -kInf, mnval = kInf;
		int l;
		scanf("%d", &l);
		bool flag = 0;
		for(int j = 0; j < l; j++) {
			int x;
			scanf("%d", &x);
			if(x > mnval) flag = 1;
			mxval = max(mxval, x);
			mnval = min(mnval, x);
		}
		if(flag) mxval = kInf, mnval = -kInf;
		mx.push_back(mxval);
		mn.push_back(mnval);
	}
	sort(mx.begin(), mx.end());
	long long ans = 0;
	//for(int x : mx) printf("%d ", x); puts("");
	for(int x : mn) {
		//printf("%d\n", x);
		int k = upper_bound(mx.begin(), mx.end(), x) - mx.begin();
		ans += n - k;
	}
	printf("%lld\n", ans);
	return 0;
}
