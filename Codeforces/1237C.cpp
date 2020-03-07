#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
#define ALL(v) v.begin(), v.end()
struct P3 {
	int x, y, z;
	int id;
	bool operator < (const P& c) const {
		if(x != c.x) return x < c.x;
		if(y != c.y) return y < c.y;
		if(z != c.z) return z < c.z;
		return id < c.id;
	}
};
struct P2 {
	int y, z;
	int id;
	bool operator < (const P& c) const {
		if(y != c.y) return y < c.y;
		if(z != c.z) return z < c.z;
		return id < c.id;
	}
};

P3 p[maxn];
set<P3> s;
set<P2> s2[maxn];	 
vector<int> xx, yy, zz;
int get_id(vector<int> v, int k) {
	return lower_bound(v.begin(), v.end(), k) - v.begin() + 1;
}
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
		xx.push_back(p[i].x);
		yy.push_back(p[i].y);
		zz.push_back(p[i].z);
		p[i].id = i + 1;
		s.insert(p[i]);
	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	sort(zz.begin(), zz.end());
	xx.resize(unique(ALL(x)) - xx.begin());
	yy.resize(unique(ALL(y)) - yy.begin());
	zz.resize(unique(ALL(z)) - zz.begin());
	for(int i = 0; i < n; i++) {
		p[i].x = get_id(xx, p[i].x);
		p[i].y = get_id(yy, p[i].y);
		p[i].z = get_id(zz, p[i].z);
	}
	for(int i = 0; i < n / 2; i++) {
		auto it = s.begin();
		printf("%d %d\n", it->id, next(it)->id);
		s.erase(s.begin());
		s.erase(s.begin());
	}
	return 0;
}

