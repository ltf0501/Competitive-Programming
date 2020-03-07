#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
vector<int> g[maxn];
int n,dp[3][maxn];
void dfs(int u,int fa)
{
    dp[0][u]=1;
    int tmp=0,add=maxn;
    for(int v : g[u])if(v!=fa)
    {
        dfs(v,u);
        dp[0][u]+=min(dp[0][v],dp[1][v]);
        dp[1][u]+=min(dp[0][v],dp[2][v]);
        tmp+=min(dp[0][v],dp[2][v]);
        add=min(add,dp[0][v]-min(dp[0][v],dp[2][v]));
    }
    dp[2][u]=tmp+add;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,0);
    int ans=0;
    for(int v : g[1])ans+=dp[0][v];
    ans-=g[1].size();
    printf("%d\n",ans);
    return 0;
}
