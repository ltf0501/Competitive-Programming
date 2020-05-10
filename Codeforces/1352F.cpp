#include <bits/stdc++.h>
using namespace std;

int cnt[3];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		for(int i = 0; i < 3; i++) scanf("%d", &cnt[i]);	
		int len = cnt[0] + cnt[1] + cnt[2] + 1;
		if(cnt[1] == 0) {
			if(cnt[0] == 0) {
				for(int i = 0; i < len; i++) printf("1"); puts("");
			}
			else {
				for(int i = 0; i < len; i++) printf("0"); puts("");
			}
			continue;
		}
		vector<int> ans;
		for(int i = 0; i < cnt[0] + 1; i++) ans.push_back(0);
		for(int i = 0; i < cnt[2] + 1; i++) ans.push_back(1);
		bool flag = 0;
		for(int i = 0; i < cnt[1] - 1; i++) {
			ans.push_back(flag);
			flag ^= 1;
		}
		for(int x : ans) printf("%d", x); puts("");
	} 
	return 0;
}
