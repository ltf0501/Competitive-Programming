#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000
#define maxn 100010
int dp[2][maxn],tmp[2][maxn];
int n,k;
int l[105],r[105];
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)scanf("%d%d",&l[i],&r[i]);
    for(int i=0;i<2;i++)
        for(int j=0;j<=2*n;j++)dp[i][j]=INF;
    dp[0][0]=0;
    int pre=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<2;j++)for(int t=0;t<=2*n;t++)dp[j][t]=INF;

    }
    return 0;
}
