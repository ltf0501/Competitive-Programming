#include <bits/stdc++.h>
using namespace std;
const int kN = 5e6 + 10;
#define ALL(v) v.begin(), v.end()
string s, S;
vector<pair<string, int> ans;
int k;
vector<string> Duval(const string &s) {
	int n = int(s.size()), i = 0;
	vector<string> res;
	while(i < n) {
		int j = i + 1, k = i;
		while(j < n && s[k] <= s[j]) {
			if(s[k] < s[j]) k = i;
			else k++;
			j++;
		}
		while(i <= k) {
			res.push_back(s.substr(i, j - k));
			i += j - k;
		}
	}
	return res;
}
int min_rotate(string s) {
	s += s;
	int n = int(s.size());
	int i = 0, ans = 0;
	while(i < n / 2) {
		ans = i;
		int j = i + 1, k = i;
		while(j < n && s[k] <= s[j]) {
			if(s[k] < s[j]) k = i;
			else k++;
			j++;
		}
		while(i <= k) 
			i += j - k;
	}
	return ans;
}
vector<int> Z(string s) {
	int n = int(s.size());
	int l = 0, r = 0;
	vector<int> z(n);

	for(int i = 0; i < n; i++) {
		if(i > r) {
			l = r = i;
			while(r < n && s[r] == s[r - l]) r++;
			z[i] = r - l;
			r--;
		}
		else {
			if(z[i - l] < r - l + 1) {
				z[i] = z[i - l];
			}
			else {
				l = i;
				while(r < n && s[r] == s[r - l]) r++;
				z[i] = r - l;
				r--;
			}
		}
	}
	z[0] = n;
	return z;
}
int main() { 
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s >> k;
	if(k == 1) {
		string S = s;
		reverse(ALL(S));
		cout << (s < S ? s : S) << '\n';
		return 0;
	}
	reverse(ALL(s));
	auto v = Duval(s);
	//cout << s << '\n';
	//for(auto t : v) cout << t << ' '; cout << '\n';

	while(k > 2 && !v.empty()) {
		auto tmp = v.back();
		int cnt = 0;
		while(!v.empty() && v.back() == tmp) 
			cnt++, v.pop_back();

		//if(int(tmp.size()) == 1) {
		//	if(!int(ans.size()) || ans.back().second == 1) {
		//		ans.push_back({"", 0}); // no-rev
		//		k--;
		//	}
		//}
		//else {
		//	ans.push_back({"", 1}); // rev
		//	k--;
		//}
		for(int i = 0; i < cnt; i++) ans.back().first += tmp;
		k--;
	}
	if(v.empty()) {
		cout << ans << '\n';
		return 0;
	}

	string T;
	for(auto tmp : v) T += tmp;
	reverse(ALL(T));

	return 0;
}
