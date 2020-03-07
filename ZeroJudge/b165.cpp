#include<bits/stdc++.h>
using namespace std;
#define maxn 305
#define inf 1000000000
int d[maxn][maxn];
main()
{
    int n,s;scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)d[i][j]=inf;
    for(int i=1;i<n;i++)
    {
        int x,y,v;scanf("%d%d%d",&x,&y,&v);
        d[x][y]=d[y][x]=v;
    }
    for(int i=1;i<=n;i++)d[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    int ans=inf;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(d[i][j]<=s)
            {
                int t=0;
                for(int k=1;k<=n;k++)t=max(t,d[i][k]+d[k][j]-d[i][j]);
                ans=min(ans,t/2);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
