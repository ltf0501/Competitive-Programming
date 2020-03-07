#include<bits/stdc++.h>
using namespace std;
#define maxn 40010
#define ll long long
vector<int> g[maxn];
int n,m;
int tmp[2][maxn],pos[maxn],up[maxn];
ll sum[maxn];
int mx_a,mx_b;
int mx[2][maxn];
void dfs1(int u,int fa)
{
    pos[u]=-1;
    for(int v : g[u])if(v!=fa)
    {
        dfs1(v,u);
        if(tmp[0][v]+1>tmp[0][u])
            pos[u]=v,tmp[1][u]=tmp[0][u],tmp[0][u]=tmp[0][v]+1;
        else if(tmp[0][v]+1>tmp[1][u])tmp[1][u]=tmp[0][v]+1;
    }
}
void dfs2(int u,int fa)
{
    if(u!=1)
    {
        up[u]=1+max(up[fa],(pos[fa]==u ? tmp[1][fa] : tmp[0][fa]));
    }
    for(int v : g[u])if(v!=fa)
        dfs2(v,u);
}
main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<n;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            g[x].push_back(y),g[y].push_back(x);
        }
        dfs1(1,-1);
        dfs2(1,-1);
        mx_a=0;
        for(int i=1;i<=n;i++)
        {
            mx[0][i]=max(tmp[0][i],up[i]);
            mx_a=max(mx_a,mx[0][i]);
        }
        for(int i=1;i<=n;i++)g[i].clear();
        memset(tmp,0,sizeof(tmp));
        memset(up,0,sizeof(up));
        for(int i=1;i<m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            g[x].push_back(y),g[y].push_back(x);
        }
        dfs1(1,-1);
        dfs2(1,-1);
        mx_b=0;
        for(int i=1;i<=m;i++)
        {
            mx[1][i]=max(tmp[0][i],up[i]);
            mx_b=max(mx_b,mx[1][i]);
        }
        memset(tmp,0,sizeof(tmp));
        memset(up,0,sizeof(up));
        for(int i=1;i<=m;i++)g[i].clear();
        //for(int i=1;i<=n;i++)printf("%d ",mx[0][i]);puts("");
       // for(int i=1;i<=m;i++)printf("%d ",mx[1][i]);puts("");
        sort(mx[0],mx[0]+n+1);
        sort(mx[1],mx[1]+m+1);
        ll ret=0;
        for(int i=1;i<=m;i++)sum[i]=sum[i-1]+mx[1][i];
        int s=max(mx_a,mx_b);
        int cur=m;
        for(int i=1;i<=n;i++)
        {
            while(cur && 1+mx[0][i]+mx[1][cur]>s)cur--;
            //printf("%d %d\n",i,cur);
            ret+=(1ll*(m-cur)*(1+mx[0][i])+sum[m]-sum[cur])+1ll*cur*s;
        }
        double ans=(double)ret/(double)(n*m);
        printf("%.3f\n",ans);
    }
    return 0;
}
