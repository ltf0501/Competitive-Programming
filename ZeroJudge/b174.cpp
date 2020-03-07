#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 200000
vector<int> G[maxn];
int dp[maxn][2],dp2[maxn];
void dfs1(int u,int fa)
{
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v!=fa)
        {
            dfs1(v,u);
            dp[u][1]=max(dp[u][1],dp[v][0]+1);
            if(dp[u][0]<dp[u][1])swap(dp[u][0],dp[u][1]);
        }
    }
}
void dfs2(int u,int fa)
{
    if(u)
    {
        if(dp[u][0]+1==dp[fa][0])dp2[u]=max(dp[fa][1],dp2[fa])+1;
        else dp2[u]=max(dp[fa][0],dp2[fa])+1;
    }
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa)continue;
        dfs2(v,u);
    }
}
main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(dp,0,sizeof(dp));memset(dp2,0,sizeof(dp2));
        for(int i=0;i<n;i++)G[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        dfs1(0,-1);
        dfs2(0,-1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i][0]+dp[i][1]);
            ans=max(ans,dp[i][0]+dp2[i]);
        }
        //printf("%d\n",ans);
        for(int i=0;i<n;i++)
        {
            if(ans==dp[i][0]+dp[i][1] || ans==dp[i][0]+dp2[i])printf("%d\n",i);
        }
    }
    return 0;
}
