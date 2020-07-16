#include <bits/stdc++.h>
using namespace std;
const int kN = 1e3 + 10;

int a[kN];
bool cmp(const int &i, const int &j) {
	return a[i] < a[j];
}
int main() {
	int n; scanf("%d", &n);
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]), v.emplace_back(a[i], i);
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++) a[v[i].second] = i;

	vector<pair<int, int>> ans;
	for(int i = n - 1; i >= 0; i--) {
		vector<int> id(i);
		for(int j = 0; j < i; j++) id[j] = j; 
		sort(id.begin(), id.end(), cmp);

		for(int j : id) {
			if(a[j] > a[i]) {
				ans.emplace_back(j, i);
				swap(a[j], a[i]);
			}
		}
	}

	for(int i = 0; i < n - 1; i++) assert(a[i] < a[i + 1]);

	printf("%d\n", int(ans.size()));
	for(auto p : ans) printf("%d %d\n", p.first + 1, p.second + 1);

	return 0;
}
