#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
bool dp[2][105][105];
int n,m,a,b,c,d;
main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int k;scanf("%d",&k);
    dp[0][a][b]=1;
    for(int i=0;i<k;i++)
    {
        int s;
        memset(dp[(i&1)^1],false,sizeof(dp[(i&1)^1]));
        scanf("%d",&s);
        for(int j=0;j<n;j++)
            for(int l=0;l<m;l++)
                if(dp[i&1][j][l])dp[(i&1)^1][(j+s)%n][l]=dp[(i&1)^1][(j-s+100*n)%n][l]=dp[(i&1)^1][j][(l+s)%m]=dp[(i&1)^1][j][(l-s+100*m)%m]=1;
    }
    if(dp[k&1][c][d])puts("YES");
    else puts("NO");
    return 0;
}
