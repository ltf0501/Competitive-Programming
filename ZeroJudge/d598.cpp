#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define inf 10000000
int d[25][25],treasure[20],next[25];
int m,n,ans,finds;
void dfs(int now,int finds,int L)
{
    if(finds==m)
    {
        ans=min(ans,L+d[now][n]);
        return ;
    }
    if(L+d[now][n]+(m-finds-1)>=ans)return ;
    int pre=0;
    for(int i=next[0];i;pre=i,i=next[i])
    {
        if(d[now][treasure[i]])
        {
            next[pre]=next[i];
            dfs(treasure[i],finds+1,L+d[now][treasure[i]]);
            next[pre]=i;
            puts("°®");
        }
    }
}
main()
{
    while(scanf("%d%d",&m,&n)==2)
    {
        for(int i=1;i<=n;i++)scanf("%d",&treasure[i]);
        for(int i=0;i<m;i++)next[i]=i+1;
        next[m]=0;
        sort(treasure+1,treasure+n+1);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int s;
                scanf("%d",&s);
                d[i][j]=s;
                if(i!=j && !s)d[i][j]=inf;
            }
        }
        for(int k=1;k<=m;k++)//floyd
        {
            for(int i=1;i<=m;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    if(d[i][k]<inf && d[k][j]<inf)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        ans=inf;finds=0;
        if(treasure[1]==1){finds++;next[0]=next[1];}
        dfs(1,finds,0);
        printf("%d\n",ans);

        /*
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)printf("%d ",d[i][j]);
            puts("");
        }
        */
    }
    return 0;
}
