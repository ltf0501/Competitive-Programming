#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	int n = s.length();
	string t;
	int i = 0, j = n - 1;
	while(i + 3 <= j) {
		int cnt[3] = {0};
		cnt[s[i] - 'a']++, cnt[s[i + 1] - 'a']++;
		cnt[s[j] - 'a']++, cnt[s[j - 1] - 'a']++;
		if(cnt[0] == 2) t += 'a';
		else if(cnt[1] == 2) t += 'b';
		else t += 'c';
		i += 2, j -= 2;
	}
	string tt = t; reverse(tt.begin(), tt.end());
	if(i <= j) t += s[i];
	t += tt;
	cout << t << '\n';
	return 0;
}
