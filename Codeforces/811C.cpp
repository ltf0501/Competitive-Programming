#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
int a[maxn],l[maxn],r[maxn],k[maxn],tk[maxn],p[maxn];
vector<int> g[maxn];
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt,topo[maxn];
int in[maxn],out[maxn];
vector<int> scc_G[maxn];
stack<int> S;
int node=0;
int s[maxn];
void dfs(int u)
{
    pre[u]=lowlink[u]=++dfs_clock;
    S.push(u);
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!pre[v])
        {
            dfs(v);
            lowlink[u]=min(lowlink[u],lowlink[v]);
        }
        else if(!sccno[v])lowlink[u]=min(lowlink[u],pre[v]);
    }
    if(lowlink[u]==pre[u])
    {
        scc_cnt++;
        for(;;)
        {
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            if(x==u)break;
        }
    }
}
void find_scc()
{
    dfs_clock=scc_cnt=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=node;i++)
        if(!pre[i])dfs(i);
}
int dfs2(int u)
{
    int ans=p[u];
    for(int v : scc_G[u])
    {
        ans^=dfs2(v);
    }
    return s[u]=ans;
}
int dfs3(int u)
{
    int ans=0;
    for(int v : scc_G[u])
    {
        ans^=dfs3(v);
    }
    return max(dfs2(u),ans);
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(!tk[a[i]])k[++node]=a[i];
        r[tk[a[i]]]=i;
        if(!l[tk[a[i]]])l[tk[a[i]]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=node;j++)
        {
            if(k[j]==a[i])continue;
            if(l[j]<i && i<r[j])g[j].push_back(tk[a[i]]);
        }
    }
    find_scc();
    for(int i=1;i<=node;i++)p[sccno[i]]^=k[i];
    for(int u=1;u<=node;u++)
    {
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(sccno[u]!=sccno[v])scc_G[sccno[u]].push_back(sccno[v]),in[sccno[v]]++;
        }
    }
    int ans=0;
    //for(int i=1;i<=scc_cnt;i++)dfs2(i);
    for(int i=1;i<=scc_cnt;i++)
        if(!in[i])ans+=dfs3(i);
    //printf("%d\n",scc_cnt);
    printf("%d\n",ans);
    return 0;
}
