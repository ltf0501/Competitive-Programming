#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 400+5
#define inf 100000000
int maps[maxn][maxn],dis[maxn][maxn];
main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)maps[i][j]=maps[j][i]=dis[i][j]=dis[j][i]=inf;
        for(int i=1;i<=m;i++)
        {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            u--;v--;
            if(d<maps[u][v])
            {
                maps[u][v]=maps[v][u]=dis[u][v]=dis[v][u]=d;
            }
        }
        /*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)printf("%d ",maps[i][j]);
            puts("");
        }
        */
        int ans=inf;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
                for(int k=j+1;k<i;k++)
                {
                    int d=dis[j][k]+maps[j][i]+maps[i][k];
                    ans=min(d,ans);
                }

            for(int j=0;j<n;j++)
                for(int k=j+1;k<n;k++)
                {
                    int d=dis[j][i]+dis[i][k];
                    if(d<dis[j][k])
                        dis[j][k]=dis[k][j]=d;
                }

        }
        if(ans==inf)puts("No solution.\n");
        else printf("%d\n",ans);
    }
    return 0;
}
