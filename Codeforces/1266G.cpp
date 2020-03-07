#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int sa[maxn], tmp[2][maxn], cnt[maxn], hi[maxn], r[maxn];
// sa[i]: sa[i]-th suffix is the i-th smallest suffix
// hi[i]: LCP of suffix sa[i] and suffix sa[i - 1]
void build(const vector<int> &s) {
	int *rnk = tmp[0], *rkn = tmp[1];
	int sigma = 256;
	int n = s.size();
	for(int i = 0; i < 256; i++) cnt[i] = 0;
	for(int i = 0; i < n; i++) cnt[rnk[i] = s[i]]++;
	for(int i = 1; i < 256; i++) cnt[i] += cnt[i - 1];
	for(int i = n - 1; i >= 0; i--) sa[--cnt[s[i]]] = i;
	for(int k = 1; k < n; k <<= 1) {
		for(int i = 0; i < sigma; i++) cnt[i] = 0;
		for(int i = 0; i < n; i++) cnt[rnk[i]]++;
		for(int i = 1; i < sigma; i++) cnt[i] += cnt[i - 1];
		int *sa2 = rkn;
		int p = 0;
		for(int i = n - k; i < n; i++) sa2[p++] = i;
		for(int i = 0; i < n; i++) {
			if(sa[i] >= k) sa2[p++] = sa[i] - k;
		}
		for(int i = n - 1; i >= 0; i--) sa[--cnt[rnk[sa2[i]]]] = sa2[i];
		rkn[sa[0]] = p = 0;
		for(int i = 1; i < n; i++) {
			if(!(rnk[sa[i - 1]] == rnk[sa[i]] && sa[i - 1] + k < n && rnk[sa[i - 1] + k] == rnk[sa[i] + k])) p++;
			rkn[sa[i]] = p;
		}
		swap(rnk, rkn);
		if(p == n - 1) break;
		sigma = p + 1;
	}

	for(int i = 0; i < n; i++) r[sa[i]] = i;
	int id = 0; hi[0] = 0;
	for(int i = 0; i < n; i++) {
		if(!r[i]) {id = 0; continue;}
		while(i + id < n && s[i + id] == s[sa[r[i] - 1] + id]) id++;
		hi[r[i]] = id ? id-- : 0;
	}
}

int main() {
	int n; scanf("%d", &n);
	vector<int> v;
	vector<int> a(n);
	for(int i = 0; i < n; i++) a[i] = i;
	do {
		for(int x : a) v.push_back(x + 1);
	} while(next_permutation(a.begin(), a.end()));
	v.push_back(n + 1);
	build(v);
	//for(int i = 0; i < v.size(); i++) printf("%d ", sa[i]); puts("");	
	//for(int i = 0; i < v.size(); i++) printf("%d ", hi[r[i] + 1]); puts("");
	for(int i = 0; i < n; i++) a[i] = i;
	int k = 0;
	int cur = 1;
	do {
		k++;
		//if(a[0] != n - 1) continue;
		if(a[0] == cur)	puts(""), cur++;
		for(int x : a) printf("%d ", x + 1); printf(": ");
		printf("LCP = %d\n", hi[r[(k - 1) * n] + 1]);
	} while(next_permutation(a.begin(), a.end()));
	return 0;
}
