#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 505
#define INF 1<<15
int n,m;
int d[maxn][maxn];
main()
{
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)d[i][j]=INF;

        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            d[a][b]=1;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

        int ans=INF;
        for(int i=1;i<=n;i++)ans=min(ans,d[i][i]);
        if(ans==INF)puts("0");
        else printf("%d\n",ans);
    }
    return 0;
}
