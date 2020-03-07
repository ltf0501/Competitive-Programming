#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int sa[maxn], tmp[2][maxn], cnt[maxn], hi[maxn], r[maxn];
// sa[i]: sa[i]-th suffix is the i-th smallest suffix
// hi[i]: LCP of suffix sa[i] and suffix sa[i - 1]
void build(string s) {
		memset(sa, 0, sizeof(sa));
		memset(tmp, 0, sizeof(tmp));
		memset(hi, 0, sizeof(hi));
		memset(r, 0, sizeof(r));
        int *rnk = tmp[0], *rkn = tmp[1];
        int sigma = 256;
        int n = s.length();
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
int sta[maxn][2];
ll top, tot;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int k;
	while(cin >> k && k) {
		string s, t;
		cin >> s >> t;
		int n = s.length();
		s += '@' + t;
		build(s);
		int len = s.length();
		ll ans = 0;
		
		for(int i = 1; i <= len; i++) {
			if(hi[i] < k) top = tot = 0;
			else {
				int cnt = 0;
				if(sa[i - 1] < n) cnt++, tot += hi[i] - k + 1;
				while(top && hi[i] <= sta[top - 1][0]) {
					top--;
					tot -= sta[top][1] * (sta[top][0] - hi[i]);
					cnt += sta[top][1];
				}
				sta[top][0] = hi[i], sta[top++][1] = cnt;
				if(sa[i] > n) ans += tot;
			}
		}

		for(int i = 1; i <= len; i++) {
			if(hi[i] < k) top = tot = 0;
			else {
				int cnt = 0;
				if(sa[i - 1] > n) cnt++, tot += hi[i] - k + 1;
				while(top && hi[i] <= sta[top - 1][0]) {
					top--;
					tot -= sta[top][1] * (sta[top][0] - hi[i]);
					cnt += sta[top][1];
				}
				sta[top][0] = hi[i], sta[top++][1] = cnt;
				if(sa[i] < n) ans += tot;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}
