#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
char c[maxn], d[maxn];
int main() {
	scanf("%s", c);
	int n = strlen(c);
	int cnt = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(c[i] == '0') cnt++;
		else {
			if(cnt == 0) c[i] = '0';
			else cnt--;
		}
	}
	printf("%s\n", c);
	return 0;
}
