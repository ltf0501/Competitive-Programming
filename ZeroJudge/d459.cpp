#include<bits/stdc++.h>
using namespace std;
#define maxn 20000+5
int n;
vector<int> g[maxn];
int dp[maxn];
void dfs(int u,int fa)
{
    dp[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        dfs(v,u);
        dp[u]+=dp[v];
    }
}
main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)printf("%5d-%5d\n",i,dp[i]);
    return 0;
}
