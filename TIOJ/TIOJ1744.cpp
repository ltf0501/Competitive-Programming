#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define ll long long
vector<int> g[maxn],scc_g[maxn];
int pre[maxn],dfs_clock=0;
int sccno[maxn],scc_cnt=0;
ll c[maxn],scc_c[maxn];
stack<int> S;
int a[maxn];
int dfs(int u)
{
    int lowu=pre[u]=++dfs_clock;
    S.push(u);
    for(int v : g[u])
    {
        if(!pre[v])
        {
            lowu=min(lowu,dfs(v));
        }
        else if(!sccno[v])lowu=min(lowu,pre[v]);
    }
    if(lowu==pre[u])
    {
        scc_cnt++;
        while(1)
        {
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            scc_c[scc_cnt]+=c[x];
            if(x==u)break;
        }
    }
    return lowu;
}
ll d[maxn];
queue<int> q;
bool vis[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    for(int i=1;i<=n;i++)
        if(!pre[i])dfs(i);
    //printf("num = %d\n",scc_cnt);
    //for(int i=1;i<=n;i++)printf("%d ",sccno[i]);puts("");
    //for(int i=1;i<=scc_cnt;i++)printf("%d ",scc_c[i]);puts("");
    for(int u=1;u<=n;u++)
    {
        for(int v : g[u])
            if(sccno[u]!=sccno[v])scc_g[sccno[u]].push_back(sccno[v]);
    }
    int st,p;scanf("%d%d",&st,&p);
    //for(int i=1;i<=scc_cnt;i++)printf("%d ",dp[i]);puts("");
    /*
    for(int i=1;i<=scc_cnt;i++)
    {
        printf("%d: ",i);
        for(int v : scc_g[i])printf("%d ",v);
        puts("");
    }
    */
    ll mx=0;
    d[sccno[st]]=scc_c[sccno[st]];
    vis[sccno[st]]=1;
    q.push(sccno[st]);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int v : scc_g[u])if(d[v]<d[u]+scc_c[v])
        {
            d[v]=d[u]+scc_c[v];
            if(!vis[v])
            {
                vis[v]=1;
                q.push(v);
            }
        }
    }
    for(int i=1;i<=p;i++)
    {
        int x;scanf("%d",&x);
        mx=max(mx,d[sccno[x]]);
    }
    printf("%lld\n",mx);

    return 0;
}
