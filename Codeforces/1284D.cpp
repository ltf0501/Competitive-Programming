#include <bits/stdc++.h>
using namespace std;
const int kN = 1e5 + 10;
const int kInf = 1e9 + 10;
typedef pair<int, int> pii;
#define F first
#define S second
#define ALL(v) v.begin(), v.end()
struct Event {
	int pos, id, flag;
	bool operator < (const Event &r) const {
		if(pos != r.pos) return pos < r.pos;
		return flag < r.flag;
	}
};
int n;
vector<int> v;
int get_id(int x) {
	return lower_bound(ALL(v), x) - v.begin() + 1;
}
bool check(vector<pii> a, vector<pii> b) {
	vector<Event> events;
	for(int i = 0; i < n; i++) {
		auto p = a[i];
		events.push_back({p.F, i, 1});
		events.push_back({p.S + 1, i, -1});
	}
	sort(ALL(events));
	multiset<int> st, ed;	
	st.insert(-kInf), ed.insert(kInf);
	for(auto e : events) {
		int id = e.id;
		if(e.flag == 1) {
			int e_min = *ed.begin();
			int s_max = *prev(st.end());
			if(b[id].F > e_min || b[id].S < s_max) return 1;
			st.insert(b[id].F), ed.insert(b[id].S);
		}
		else {
			st.erase(st.find(b[id].F));
			ed.erase(ed.find(b[id].S));
		}
	}
	return 0;	
}
int main() {
	scanf("%d", &n);
	vector<pii> a(n), b(n);
	for(int i = 0; i < n; i++) scanf("%d%d%d%d", &a[i].F, &a[i].S, &b[i].F, &b[i].S);
	for(int i = 0; i < n; i++) {
		v.push_back(a[i].F);
		v.push_back(a[i].S);
		v.push_back(b[i].F);
		v.push_back(b[i].S);
	}
	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());
	int m = int(v.size());
	for(int i = 0; i < n; i++) {
		a[i].F = get_id(a[i].F);
		a[i].S = get_id(a[i].S);
		b[i].F = get_id(b[i].F);
		b[i].S = get_id(b[i].S);
	}
	bool flag = check(a, b) | check(b, a);
	if(flag) puts("No");
	else puts("Yes");
	return 0;
}
