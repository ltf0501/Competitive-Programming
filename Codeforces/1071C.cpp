#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, N;
int a[maxn], b[maxn];
int cnt[maxn];
vector<tuple<int, int, int>> ans;
void gao(int x, int d) {
	a[x] ^= 1, a[x - d] ^= 1, a[x + d] ^= 1;
	ans.push_back(make_tuple(x - d, x, x + d));
}
void dfs(int now, int d) {
	//if(now - d < 0 || now + d > n - 1) return;
	if(now == n - 1) {
		bool flag = 1;
		for(int i = 0; i < n; i++) if(a[i]) flag = 0;
		if(flag) {
			puts("YES");
			printf("%d\n", (int)ans.size());
			for(auto p : ans) printf("%d %d %d\n", get<0>(p) + 1, get<1>(p) + 1, get<2>(p) + 1);
			/*
			for(auto p : ans) cnt[get<0>(p)]++,cnt[get<1>(p)]++,cnt[get<2>(p)]++;	
			bool flag = 1;
			for(int i = 0; i < N; i++) 
				if(b[i] ^ (cnt[i] & 1)) flag = 0, printf("%d ", i); puts("");
			printf("sz = %d, N = %d\n", (int)ans.size(), N);
			if((int)ans.size() > N / 3 + 12) flag = 0;
			if(flag) puts("OK");
			else puts("Wrong");
			*/
			exit(0);
		}
		return;
	}
	//printf("now = %d\n, d = %d\n", now, d);
	
	if(now - d - 1 < 0 || now + d + 1 > n - 1) dfs(now + 1, 1);
	else dfs(now, d + 1);

	gao(now, d);
	if(now - d - 1 < 0 || now + d + 1 > n - 1) dfs(now + 1, 1);
	else dfs(now, d + 1);

	a[now] ^= 1, a[now - d] ^= 1, a[now + d] ^= 1;
	ans.pop_back();
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), b[i] = a[i];
	N = n;
	while(n >= 11) {
		if(a[n - 1]) {
			if(a[n - 2] && a[n - 3]) { // ???111
				gao(n - 2, 1); n -= 3;
				continue;
			}
			else {
				if(!a[n - 4]) { 
					if(a[n - 5] && a[n - 6]) {
						if(a[n - 2]) { // 110011
							gao(n - 5, 4), gao(n - 6, 4);
						}
						else if(a[n - 3]) {// 110101
							gao(n - 3, 2), gao(n - 7, 1);
						}
						else { // 110001
							gao(n - 3, 2), gao(n - 6, 3);
						}
					}
					else if(a[n - 5]) {
						if(a[n - 2]) {// 010011
							gao(n - 2, 1), gao(n - 5, 2);
						}
						else if(a[n - 3]) {// 010101
							gao(n - 3, 2);
						}
						else {// 010001
							gao(n - 5, 4);
						}
					}
					else if(a[n - 6]) {
						if(a[n - 2]) {// 100011
							gao(n - 2, 1), gao(n - 6, 3);
						}
						else if(a[n - 3]) {// 100101
							gao(n - 3, 2), gao(n - 6, 1);
						}
						else {// 100001
							gao(n - 4, 3), gao(n - 6, 2);
						}

					}
					else {
						if(a[n - 2]) {// 000011
							gao(n - 5, 4), gao(n - 5, 3);
						}
						else if(a[n - 3]) {// 000101
							gao(n - 5, 4), gao(n - 5, 2);
						}
						else { // 000001
							gao(n - 4, 3), gao(n - 7, 3);
						} 
					}
				}
				else {
					if(a[n - 5] && a[n - 6]) {
						if(a[n - 2]) {// 111011
							gao(n - 5, 4), gao(n - 4, 2);
						}
						else if(a[n - 3]) {// 111101
							gao(n - 3, 2), gao(n - 6, 2);
						}
						else {// 111001
							gao(n - 4, 3), gao(n - 6, 1);
						}
					}
					else if(a[n - 5]) {
						if(a[n - 2]) {// 011011
							gao(n - 4, 3), gao(n - 5, 3);
						}
						else if(a[n - 3]) {// 011101
							gao(n - 3, 2), gao(n - 7, 3);
						}
						else {// 011001
							gao(n - 4, 3), gao(n - 7, 2);
						}
					}
					else if(a[n - 6]) {
						if(a[n - 2]) {// 101011
							gao(n - 4, 3), gao(n - 6, 4);
						}
						else if(a[n - 3]) {// 101101
							gao(n - 4, 3), gao(n - 6, 3);
						}
						else {// 101001
							gao(n - 4, 3), gao(n - 7, 1);
						}

					}
					else {
						if(a[n - 2]) {// 001011
							gao(n - 4, 2), gao(n - 6, 5);
						}
						else if(a[n - 3]) {// 001101
							gao(n - 4, 1), gao(n - 5, 4);
						}
						else {// 001001
							gao(n - 4, 3);
						} 
					}
				}
				n -= 6;
			}
		}
		else n--;
	}
	if(N >= 8 && n < 8) n = 8;
	dfs(1, 1);
	puts("NO");
	return 0;
}
