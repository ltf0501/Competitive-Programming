#include <bits/stdc++.h>
using namespace std;
const int kN = 1e6 + 10;

int n;
char s[kN];
int cal(char c) {
	if(c == '(') return 1;
	return -1;
}
int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	int ans = 0;
	int tot = 0;
	for(int i = 1; i <= n; i++) tot += cal(s[i]);
	if(tot != 0) return puts("-1"), 0;
	for(int i = 1, j = 1; i <= n; ) {
		int sum = 0;
		bool flag = s[i] == ')';
		sum += cal(s[j++]);
		while(j <= n) {
			sum += cal(s[j++]);
			if(sum == 0) break;
		}
		if(flag) ans += j - i;
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}
