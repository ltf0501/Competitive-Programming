#include <bits/stdc++.h>
using namespace std;
#define bye \
	if(flag) {puts("White"); continue;}
const int kN = 5e5 + 10;
int n;
vector<int> g[kN];
char c[kN];
int deg[kN];
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) g[i].clear(), deg[i] = 0;
		for(int i = 1, x, y; i < n; i++) {
			scanf("%d%d", &x, &y);
			g[x].push_back(y), g[y].push_back(x);
			deg[x]++, deg[y]++;
		}
		scanf("%s", c + 1);

		if(n == 2) {puts("Draw"); continue;}
		bool flag = 0;
		for(int i = 1; i <= n; i++) flag |= (deg[i] >= 4);
		bye;

		vector<int> v;
		for(int i = 1; i <= n; i++) if(deg[i] == 3) {
			v.push_back(i);
			int cnt = 0;
			for(int x : g[i]) flag |= (c[x] == 'W'), cnt += deg[x] > 1;
			if(c[i] == 'W' || cnt > 1) flag = 1;
		}
		bye;

		if(v.size() >= 2) {
			for(int i = 1; i <= n; i++) flag |= (c[i] == 'W');
			bye;

			int now = v[0], pre = -1, dis = 0;
			while(now != v[1]) {
				dis++;
				for(int x : g[now]) 
					if(x != pre && deg[x] > 1) {pre = now, now = x; break;}
			}
			if(dis & 1) puts("Draw");
			else puts("White");
		}
		else if(v.size() == 1) {
			vector<int> leaf;
			for(int x : g[v[0]]) if(deg[x] == 1) leaf.push_back(x);

			int le = -1;	
			for(int i = 1; i <= n; i++) if(deg[i] == 1) {
				bool tmp = 0;
				for(int x : leaf) if(i == x) tmp = 1;
				if(!tmp) {le = i; break;}
			}

			for(int i = 1; i <= n; i++) 
				if(c[i] == 'W' && i != le) flag = 1;
			bye;

			if(n % 2 == 0 && c[le] == 'W') puts("White");
			else puts("Draw");
		}
		else {
			for(int i = 1; i <= n; i++)
				if(deg[i] > 1 && c[i] == 'W' && n >= 4) flag = 1;
			bye;

			int cnt = 0;
			for(int i = 1; i <= n; i++)
				if(c[i] == 'W') cnt++;
			if(cnt >= 2 && (n & 1)) puts("White");
			else puts("Draw");
		} 
	}
	return 0;
}
