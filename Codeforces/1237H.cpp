#include <bits/stdc++.h>
using namespace std;
const int kN = 4010;
string a, b;
vector<int> ans;
void AddAns(int x) {
	if(!x) return;
	ans.push_back(x);
	reverse(a.begin(), a.begin() + x);
	//cerr << "flip = " << x << '\n';
	//cerr << "a = " << a << '\n';
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		cin >> a >> b;
		int n = a.size();
		vector<int> cnta(4), cntb(4);
		for(int i = 0; i < n; i += 2) {
			cnta[(a[i] - '0') + (a[i + 1] - '0') * 2]++;
			cntb[(b[i] - '0') + (b[i + 1] - '0') * 2]++;
		}
		if(cnta[0] != cntb[0] || cnta[3] != cntb[3]) {cout << "-1\n"; continue;}

		ans.clear();
		int fin = -1;
		if(cnta[1] != cntb[2]) {
			int num = cnta[1] + cnta[2];
			int pre[3] = {0};
			for(int i = 0; i < n; i += 2) {
				int x = (a[i] - '0') + (a[i + 1] - '0') * 2;	
				if(x == 1 || x == 2) pre[x]++;
				if(cnta[1] - pre[1] + pre[2] == cntb[2]) {AddAns(i + 2); break;}
			}
			if(ans.empty()) {
				pre[1] = pre[2] = 0;
				for(int i = 0; i < n; i += 2) {
					int x = (b[i] - '0') + (b[i + 1] - '0') * 2;
					if(x == 1 || x == 2) pre[x]++;
					if(cntb[1] - pre[1] + pre[2] == cnta[2]) {fin = i + 2; break;}
				}
			}
			assert(!ans.empty() || fin != -1);
		}
		//if(!ans.empty()) cerr << "ans[0] = " << ans[0] << '\n';	
		//else cerr << "fin = " << fin << '\n';
		if(fin != -1) reverse(b.begin(), b.begin() + fin);

		for(int i = n - 2; i >= 0; i -= 2) {
			int x = (b[i] - '0') + (b[i + 1] - '0') * 2;
			if(x == 1 || x == 2) x = 3 - x;
			for(int j = n - i - 2; j < n; j += 2) {
				int y = (a[j] - '0') + (a[j + 1] - '0') * 2;
				if(y == x) {
					AddAns(j), AddAns(j + 2);
					break;
				}
			}
		}

		if(fin != -1) AddAns(fin), reverse(b.begin(), b.begin() + fin);
		cout << int(ans.size()) << '\n';
		for(int x : ans) cout << x << ' '; cout << '\n';
		assert(a == b); 
	}
	return 0;
}
