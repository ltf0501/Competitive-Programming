#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		string s;
		cin >> s;
		bool flag = 0;
		int cnt = 0;
		int n = s.size();
		for(int i = 0; i < n; i++) {
			cnt += (s[i] - '0');
			flag |= s[i] == '0';
		}
		if(cnt % 3 != 0 || !flag) {cout << "cyan\n"; continue;}
		cnt = 0;
		for(int i = 0; i < n; i++) {
			cnt += ((s[i] - '0') % 2 == 0);
		}
		if(cnt == 1) cout << "cyan\n";
		else cout << "red\n";
	}
	return 0;
}
