#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 50000+10
int dfs_clock,pre[maxn],low[maxn],iscut[maxn];
int n,cnt,vis[maxn],connect[maxn];
vector<int> G[maxn];

void init()
{
    for(int i=1;i<=maxn;i++)G[i].clear();
    dfs_clock=0,cnt=0;
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    memset(iscut,0,sizeof(iscut));
    memset(vis,0,sizeof(vis));
    memset(connect,0,sizeof(connect));
}
int dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    int child=0;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!pre[v])
        {
            child++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u])iscut[u]=1;
        }
        else if(pre[v]<pre[u] && v!=fa)lowu=min(lowu,pre[v]);
    }
    if(fa<0 && child==1)iscut[u]=0;
    return low[u]=lowu;
}
void dfs2(int u)
{
    vis[u]=1;
    connect[cnt]++;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!iscut[v] && !vis[v])
        {
            dfs2(v);
        }
    }
}
main()
{
    int cas=0;
    while(scanf("%d",&n)==1 && n)
    {
        init();
        int maxpoint=1;
        for(int i=1;i<=n;i++)
        {
            int p,q;
            scanf("%d%d",&p,&q);
            G[p].push_back(q);
            G[q].push_back(p);
            maxpoint=max(maxpoint,max(p,q));
        }
        dfs(1,-1);
        /*
        for(int i=1;i<=maxpoint;i++)
        {
            printf("%d ",iscut[i]);
        }
        puts("");
        */
        int cut=1;
        for(int i=1;i<=maxpoint;i++)
        {
            if(iscut[i])cut++;
            if(!vis[i] && !iscut[i])
            {
                cnt++;
                dfs2(i);
            }
        }
        long long ans=1;
        //for(int i=1;i<=cnt;i++)printf("%d ",connect[i]);
        //puts("");
        for(int i=1;i<=cnt;i++)ans*=(long long)connect[i];
        if(cut==0)ans=2;
        printf("Case %d: %d %lld\n",++cas,cut,ans);

    }
    return 0;
}
