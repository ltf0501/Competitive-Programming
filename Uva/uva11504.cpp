#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+5
int pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt,topo[maxn];
int n,m;
vector<int> g[maxn];
stack<int> S;
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
    for(int i=1;i<=n;i++)
        if(!pre[i])dfs(i);
}
int in[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=n;i++)g[i].clear();
        //for(int i=1;i<=n;i++)g2[i].clear();
        memset(in,0,sizeof(in));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            g[x].push_back(y);
        }
        find_scc();
        int ans=0;
        for(int u=1;u<=n;u++)
        {
            for(int i=0;i<g[u].size();i++)
            {
                int v=g[u][i];
                if(sccno[v]!=sccno[u])in[sccno[v]]++;
            }
        }
        for(int i=1;i<=scc_cnt;i++)if(!in[i])ans++;
        printf("%d\n",ans);
    }
    return 0;
}
