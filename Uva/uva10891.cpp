#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int MAXN = 110;
int dp[MAXN][MAXN];
int a[MAXN], sum[MAXN];

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        sum[0] = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]), sum[i] = a[i] + sum[i-1];

        for (int i = 1; i <= n; ++i)
            dp[i][i] = a[i];

        for (int p = 2; p <= n; ++p)
        {
            for (int i = 1, j = p; j <= n; ++i, ++j)
            {
                int ans = INT_MIN;
                for (int k = i; k < j; ++k)
                {
                    int m = min(dp[i][k], dp[k+1][j]);
                    m = sum[j] - sum[i-1] - m;
                    if (ans < m)
                        ans = m;
                }
                if (ans < sum[j] - sum[i-1])
                    ans = sum[j] - sum[i-1];
                dp[i][j] = ans;
            }
        }
        printf("%d\n", 2 * dp[1][n] - (sum[n] - sum[0]));
    }
    return 0;
}
