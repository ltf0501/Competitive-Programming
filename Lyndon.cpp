#include <bits/stdc++.h>
using namespace std;
vector<int> w;
void Lyndon(int n, int m) {
	w.push_back(-1);
	while(!w.empty()) {
		w.back()++;
		for(int x : w) printf("%d ", x);
		puts("");
			
		int k = w.size();
		while(w.size() < n) {
			w.push_back(w[w.size() - k]);
		}
		
		while(!w.empty() && w.back() == m - 1) w.pop_back();
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	Lyndon(n, m);
	return 0;
}
