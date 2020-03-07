#include<bits/stdc++.h>
using namespace std;
#define maxn 10000+10
#define INF 100000000
vector<int> g[maxn];
int dp[maxn][3];
int dfs(int u,int fa,int c)
{
    if(dp[u][c])return dp[u][c];
    if(c==0)
    {
        int ans=1;
        for(int v : g[u])
        {
            if(v==fa)continue;
            ans+=min(dfs(v,u,0),min(dfs(v,u,1),dfs(v,u,2)));
        }
        return dp[u][c]=ans;
    }
    else if(c==1)
    {
        if(!g[u].size())return dp[u][c]=INF;
        int ans=0;
        int tmp=INF;
        for(int v : g[u])
        {
            if(v==fa)continue;
            ans+=min(dfs(v,u,0),dfs(v,u,1));
            tmp=min(tmp,max(dfs(v,u,0)-dfs(v,u,1),0));
        }
        ans+=tmp;
        return dp[u][c]=ans;
    }
    else
    {
        int ans=0;
        for(int v : g[u])
        {
            if(v==fa)continue;
            ans+=dfs(v,u,1);
        }
        return dp[u][c]=ans;
    }
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    int ans=min(dfs(1,0,0),dfs(1,0,1));
    printf("%d\n",ans);
    return 0;
}
