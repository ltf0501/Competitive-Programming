#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define F first
#define S second
const int kN = 1e3 + 10;
pii a[kN];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &a[i].F, &a[i].S);
	while(true) {
		vector<int> v[2][2];
		for(int i = 1; i <= n; i++) v[a[i].F & 1][a[i].S & 1].push_back(i);
		int cnt = 0;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++) cnt += !v[i][j].empty();
		if(cnt == 1) {
			int x, y;
			for(int i = 0; i < 2; i++)
				for(int j = 0; j < 2; j++) if(!v[i][j].empty()) x = i, y = j;
			for(int i = 1; i <= n; i++) a[i].F = (a[i].F - x) >> 1, a[i].S = (a[i].S - y) >> 1;
		}
		else {
			if(v[0][0].size() + v[1][1].size() > 0 && v[0][1].size() + v[1][0].size() > 0) {
				printf("%d\n", v[0][0].size() + v[1][1].size());
				for(int x : v[0][0]) printf("%d ", x);
				for(int x : v[1][1]) printf("%d ", x);
				puts("");
			}
			else {
				if(v[0][0].size() + v[1][1].size() > 0) {
					printf("%d\n", v[0][0].size());
					for(int x : v[0][0]) printf("%d ", x); puts(""); 
				}
				else {
					printf("%d\n", v[0][1].size());
					for(int x : v[0][1]) printf("%d ", x); puts(""); 
				}
			}
			return 0;
		}
	}
	return 0;
}
