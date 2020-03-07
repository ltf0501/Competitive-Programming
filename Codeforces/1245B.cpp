#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
const char *w = "RPS";
char s[maxn];
bool vis[maxn];
char ans[maxn];
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		scanf("%s", s);	
		int tot = (n + 1) / 2;
		int sa = 0, sb = 0, sc = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] == w[0]) sb++;
			if(s[i] == w[1]) sc++;
			if(s[i] == w[2]) sa++;
		}
		int cnt = min(a, sa) + min(b, sb) + min(c, sc);
		if(cnt >= tot) {
			puts("YES");
			memset(vis, 0, sizeof(vis));
			for(int i = 0; i < n; i++) {
				if(s[i] == w[0] && b) {
					b--;
					ans[i] = w[1];
					vis[i] = 1;
				}
				if(s[i] == w[1] && c) {
					c--;
					ans[i] = w[2];
					vis[i] = 1;
				}
				if(s[i] == w[2] && a) {
					a--;
					ans[i] = w[0];
					vis[i] = 1;
				}
			}
			for(int i = 0; i < n; i++) if(!vis[i]) {
				if(a) {
					ans[i] = w[0];
					a--;
				}
				else if(b) {
					ans[i] = w[1];
					b--;
				}
				else ans[i] = w[2], c--;
			}
			for(int i = 0; i < n; i++) putchar(ans[i]); puts("");
		}
		else puts("NO");
	}
	return 0;
}

