#include<bits/stdc++.h>
using namespace std;
#define maxn 110
#define INF 1000000000
int d[maxn][maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)d[i][j]=INF;
        for(int i=1;i<=n;i++)d[i][i]=0;
        while(m--)
        {
            int x,y,dis;scanf("%d%d%d",&x,&y,&dis);
            d[x][y]=dis;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
                if(d[i][k]<INF && d[k][j]<INF)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        int q;scanf("%d",&q);
        while(q--)
        {
            int u,v;scanf("%d%d",&u,&v);
            if(d[u][v]==INF)puts("-1");
            else printf("%d\n",d[u][v]);
        }
    }
    return 0;
}
