#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string a, b, c;
		cin >> a >> b >> c;
		int n = a.size();
		bool flag = 1;
		for(int i = 0; i < n; i++) {
			flag &= (c[i] == a[i] || c[i] == b[i]);
		}
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
