#include <bits/stdc++.h>
using namespace std;
constexpr int kN = 2000100;
int zz[kN * 2];
int zzz[kN], zzzz[kN];
void Manacher(const string &s) {
  string t = ".";
  for (int i = 0; i < int(s.length()); ++i)
    t += s[i], t += '.';
  int l = 0, r = 0;
  for (int i = 1; i < int(t.length()); ++i) {
    zz[i] =
      (r > i ? min(zz[2 * l - i], r - i) : 1);
    while (i - zz[i] >= 0 &&
      i + zz[i] < int(t.length()) &&
      t[i - zz[i]] == t[i + zz[i]])
      ++zz[i];
    if (i + zz[i] > r) r = i + zz[i], l = i;
  }
  for (int i = 1; i <= int(s.length()); i++) {
    zzz[i] = zz[2 * i - 1] / 2;
    zzzz[i] = zz[2 * i] / 2;
  }
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		string s; cin >> s;
		int n = int(s.size());
		auto t = s + '@' + s;
		Manacher(t);
		//cerr << t << '\n';

		int len = min(n / 2, zzz[n + 1] - 1);
		//cerr << "len = " << len << '\n';
		//if(len * 2 >= n) {
		//	string s1 = s.substr(0, len);
		//	auto s2 = s1;
		//	reverse(s1.begin(), s1.end());
		//	s1 = s1 + s2;
		//	cout << s1 << '\n';
		//	continue;
		//}

		//for(int i = 1; i <= n; i++) cerr << zzz[i] << ' '; cerr << '\n';
		int pre_len = 0, suf_len = 0;
		auto S = s.substr(len, n - 2 * len);
		int N = int(S.size());
		Manacher(S);
		for(int i = 1; i <= N; i++) {
			if(i - zzz[i] + 1 <= 1) pre_len = max(pre_len, 2 * i - 1);
			if(i + zzz[i] - 1 >= N) suf_len = max(suf_len, 2 * (N - i) + 1);
			if(i < N) {
				if(i - zzzz[i] + 1 <= 1) pre_len = max(pre_len, 2 * i);
				if(i + zzzz[i] >= N) suf_len = max(suf_len, 2 * (N - i));
			}
		}

		//cerr << "pre_len = " << pre_len << ", suf_len = " << suf_len << '\n';
		string ss = s.substr(0, len); 
		if(pre_len > suf_len) ss += s.substr(len, pre_len);
		else ss += s.substr(n - len - suf_len, suf_len); 
		ss += s.substr(n - len, len);
		//cerr << "now: " << ss << '\n';
		//if(int(ss.size()) > n) {
		//	ss = ss.substr(0, n / 2);
		//	auto tt = ss;
		//	reverse(tt.begin(), tt.end());
		//	ss += tt;
		//}
		cout << ss << '\n';
	}
	return 0;
}
