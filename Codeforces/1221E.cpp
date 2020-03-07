#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q; 
	while(q--) {
		int a, b; cin >> a >> b;
		string s; cin >> s;
		int n = s.length();
		vector<int> v;
		for(int i = 0, cnt = 0; i < n; i++) {
			if(s[i] == '.') cnt++;
			if(i == n - 1 || s[i + 1] == 'X') v.push_back(cnt), cnt = 0;
		}
		int len = -1;
		int num[3] = {0};
		for(int x : v) {
			if(b <= x && x < a) num[0]++;
			else if(a <= x && x < 2 * b) num[1]++;
			else if(2 * b <= x) num[2]++, len = x;
		}
		bool flag = 1;
		if(num[0]) flag = 0;
		else {
			if(num[2] >= 2) flag = 0;
			else if(num[2] == 0) {
				if(!(num[1] & 1)) flag = 0;
			}
			else {
				bool tmp = 0;
				int nnum[3];
				for(int i = 0; i < 3; i++) nnum[i] = num[i];
				for(int i = 0; i <= len - a; i++) {
					int j = len - i - a;
					nnum[2]--;
					if(b <= i && i < a) nnum[0]++;
					else if(a <= i && i < 2 * b) nnum[1]++;
					else if(2 * b <= i) nnum[2]++;
					if(b <= j && j < a) nnum[0]++;
					else if(a <= j && j < 2 * b) nnum[1]++;
					else if(2 * b <= j) nnum[2]++;
					if(!nnum[0] && !nnum[2] && !(nnum[1] & 1)) {tmp = 1; break;}
					for(int i = 0; i < 3; i++) nnum[i] = num[i];
				}
				if(!tmp) flag = 0;
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}
