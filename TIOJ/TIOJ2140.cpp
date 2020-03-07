#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
const int maxn = 1e5 + 10;
mt19937 rng;
gp_hash_table<int, int> mp[maxn << 2];
pair<int, int> seg[maxn << 2];
int a[maxn];

void push_up(int o) {

}
void build(int l, int r, int o) {
	if(l == r) {
		seg[o] = {a[l], 1};
		mp[o].insert(make_pair(a[l], 1));
		return;
	}
	int m = (l + r) >> 1;
	build(l, m), build(m + 1, r);
	push_up(o);
}
int main() {

	return 0;
}
