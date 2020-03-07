#include <bits/stdc++.h>
using namespace std;
string a[20], b[20];
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		x--;
		cout << a[x % n] << b[x % m] << '\n';
	}
	return 0;
}
