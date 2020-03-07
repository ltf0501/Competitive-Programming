#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
typedef pair<int, int> pii;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
#define F first
#define S second
int n, m, k;
int x[maxn], y[maxn];
vector<pii> v;
vector<int> row[maxn], col[maxn];
set<pii> s;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		row[x].push_back(y), col[y].push_back(x);
		s.insert(pii(x, y));
	}
	for(int i = 0; i < n; i++) row[i].push_back(-1), row[i].push_back(m);
	for(int i = 0; i < m; i++) col[i].push_back(-1), col[i].push_back(n);
	for(int i = 0; i < n; i++) sort(row[i].begin(), row[i].end());
	for(int i = 0; i < m; i++) sort(col[i].begin(), col[i].end());
	int cur_x = 0, cur_y = 0;
	int x0 = 0, x1 = n - 1, y0 = 0, y1 = m - 1;
	int dir = 0;
	if(m == 1) dir = 1;
	while(1) {
		if(dir == 0 && y0 > y1) break;
		if(dir == 1 && x0 > x1) break;
		if(dir == 2 && y0 > y1) break;
		if(dir == 3 && x0 > x1) break;
		//printf("dir = %d\n", dir);
		if(dir == 0) {
			int k = *upper_bound(row[cur_x].begin(), row[cur_x].end(), cur_y);
			//printf("k = %d\n", k);
			k = min(k, y1 + 1);
			for(int j = k; j <= y1; j++) 
				for(int i = x0; i <= x1; i++) 
					if(s.find(pii(i, j)) == s.end()) return puts("No"), 0;
			y1 = k - 1;
			cur_y = y1;
			x0++;
		}
		if(dir == 1) {
			int k = *upper_bound(col[cur_y].begin(), col[cur_y].end(), cur_x);
			//printf("k = %d\n", k);
			k = min(k, x1 + 1);
			for(int i = k; i <= x1; i++) 
				for(int j = y0; j <= y1; j++) 
					if(s.find(pii(i, j)) == s.end()) return puts("No"), 0;
			x1 = k - 1;
			cur_x = x1;
			y1--;
		}
		if(dir == 2) {
			int k = *(--lower_bound(row[cur_x].begin(), row[cur_x].end(), cur_y));
			//printf("k = %d\n", k);
			k = max(k, y0 - 1);
			for(int j = y0; j <= k; j++)
				for(int i = x0; i <= x1; i++)
					if(s.find(pii(i, j)) == s.end()) return puts("No"), 0;
			y0 = k + 1;
			cur_y = y0;
			x1--;
		}
		if(dir == 3) {
			int k = *(--lower_bound(col[cur_y].begin(), col[cur_y].end(), cur_x));
			//printf("k = %d\n", k);
			k = max(k, x0 - 1);
			for(int i = x0; i <= k; i++)
				for(int j = y0; j <= y1; j++) 
					if(s.find(pii(i, j)) == s.end()) return puts("No"), 0;
			x0 = k + 1;
			cur_x = x0;
			y0++;
		}
		//printf("cur_x = %d, cur_y = %d\n", cur_x, cur_y);
		//printf("x0 = %d, x1 = %d, y0 = %d, y1 = %d\n", x0, x1, y0, y1);
		dir = (dir + 1) % 4;
	} 
	puts("Yes");
	return 0;
}
