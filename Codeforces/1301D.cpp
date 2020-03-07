#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, string>> ans;
void print() {
	cout << "YES\n";
	cout << int(ans.size()) << '\n';
	for(auto p : ans) cout << p.first << ' ' << p.second << '\n';
	exit(0);
}
void gao() {
	int dis = min(k, m - 1);
	if(dis >= 4) ans.push_back({dis / 4, "LLLL"});
	if(k >= m - 1) {
		if((m - 1) % 4 != 0) ans.push_back({(m - 1) % 4, "L"});
		k -= (m - 1) % 4;
	}
	else {
		if(k % 4 != 0) ans.push_back({k % 4, "L"});
		print();
	}
	k -= 4 * (dis / 4);
}
void gao2() {
	int dis = min(k, n - 1);
	if(dis >= 4) ans.push_back({dis / 4, "UUUU"});
	if(k >= n - 1) {
		if((n - 1) % 4 != 0) ans.push_back({(n - 1) % 4, "U"});
		k -= (n - 1) % 4;
	}
	else {
		if(k % 4 != 0) ans.push_back({k % 4, "U"});
		print();
	}
	k -= 4 * (dis / 4);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	if(k > 4 * m * n - 2 * m - 2 * n) {cout << "NO\n"; return 0;}
	int dis = min(k, m - 1);
	if(dis >= 4) ans.push_back({dis / 4, "RRRR"});
	if(k >= m - 1) {
		if((m - 1) % 4 != 0) ans.push_back({(m - 1) % 4, "R"});
		k -= (m - 1) % 4;
	}
	else {
		if(k % 4 != 0) ans.push_back({k % 4, "R"});
		print();
	}
	k -= 4 * (dis / 4); 
	gao();
	//cerr << "k = " << k << '\n';
	for(int i = 1; i < n && k > 0; i++) {
		ans.push_back({1, "D"});	
		k--;
		if(!k) print(); 
		if(k <= 3 * (m - 1)) {
			if(k >= 3) ans.push_back({k / 3, "RUD"});
			k %= 3;
			if(k) ans.push_back({1, "R"}), k--;
			if(k) ans.push_back({1, "U"}), k--;
			print();
		}
		if(m > 1) ans.push_back({m - 1, "RUD"});
		k -= 3 * (m - 1);
		gao();
	}
	gao2();
	print();
	return 0;
}
