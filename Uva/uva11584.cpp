#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double eps = 1e-4;
int dp[1010];
char s[1010];
int is_ok(int l, int r) {
	while (l < r) {
		if (s[l] != s[r]) return 0;
		l++, r--;
	}
	return 1;
}
int main()
{
    //freopen("H:\\in.txt","r",stdin);
    //freopen("H:\\out.txt","w",stdout);
    int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= len; i++) dp[i] = INF;
		dp[0] = 0;
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= i; j++) {
				if (is_ok(j ,i))
					dp[i] = min(dp[i], dp[j-1] + 1);
			}
		}
		printf("%d\n", dp[len]);
	}
    return 0;
}
