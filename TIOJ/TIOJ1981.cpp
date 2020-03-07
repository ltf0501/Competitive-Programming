#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int n,m;
vector<int> g[maxn],g2[maxn];
int in[maxn],dfs_clock=0,sccno[maxn],scc_cnt=0;
int a[maxn];
stack<int> S;
int dfs(int u)
{
    S.push(u);
    int lowu=in[u]=++dfs_clock;
    for(int v : g[u])
    {
        if(!in[v])
        {
            lowu=min(lowu,dfs(v));
        }
        else if(!sccno[v])lowu=min(lowu,in[v]);
    }
    if(lowu==in[u])
    {
        scc_cnt++;
        while(1)
        {
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            if(x==u)break;
        }
    }
    return lowu;
}
void build()
{
    for(int u=0;u<n;u++)for(int v : g[u])
        if(sccno[u]!=sccno[v])g2[sccno[u]].push_back(sccno[v]);
}
int dp[maxn];
int dfs2(int u)
{
    if(dp[u])return dp[u];
    int ans=0;
    for(int v : g2[u])ans=max(ans,dfs2(v));
    return dp[u]=ans+a[u];
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y);
    }
    for(int i=0;i<n;i++)if(!in[i])dfs(i);
    for(int i=0;i<n;i++)a[sccno[i]]++;
    //for(int i=0;i<n;i++)printf("%d ",sccno[i]);puts("");
    build();
    int ans=0;
    for(int i=1;i<=scc_cnt;i++)ans=max(ans,dfs2(i));
    printf("%d\n",ans);
    return 0;
}
