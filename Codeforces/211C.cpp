#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
typedef long long ll;

ll f[maxn >> 1];
ll cal(char c, int num) {
//	printf("%c %d\n", c, num);
	if(c == 'A') return (num & 1) ? f[(num >> 1) + 1] : f[(num >> 1) - 1];
	else return (num & 1) ? f[(num >> 1) + 1] : f[(num >> 1) + 2];
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	f[0] = 0, f[1] = 1;
	for(int i = 2; i < (maxn >> 1); i++) f[i] = f[i - 1] + f[i - 2];
	string s;
	cin >> s;
	int n = s.length();
	vector<int> v;
	for(int i = 0; i < n; i++) 
		if(s[i] == s[(i - 1 + n) % n]) v.push_back(i);
	if(v.empty()) return 0 * printf("%lld\n", f[(n >> 1) - 1] + f[(n >> 1) + 1]);
	ll ans = 1;
	v.push_back(v[0] + n);
	int sz = (int)v.size();
	for(int i = 0; i < sz - 1; i++) ans *= cal(s[v[i]], v[i + 1] - v[i]);
	cout << ans << '\n';
	return 0;
}
