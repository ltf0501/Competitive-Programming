#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000+10
vector<int> g[maxn];
int sum,dp[maxn],root,v1,v2;
void dfs(int u)
{
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        dfs(v);
        dp[u]+=dp[v];
    }
    if(dp[u]==sum && u!=root)
    {
        if(!v1)v1=u,dp[u]=0;
        else if(!v2)v2=u,dp[u]=0;
    }
}
main()
{
    int n;scanf("%d",&n);
    sum=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d%d",&x,&dp[i]);sum+=dp[i];
        if(x)g[x].push_back(i);
        else root=i;
    }

    if(sum%3){puts("-1");return 0;}
    sum/=3;
    v1=0,v2=0;
    dfs(root);
    //for(int i=1;i<=n;i++)printf("%d ",dp[i]);puts("");
    if(v1 && v2)printf("%d %d\n",v1,v2);
    else puts("-1");
    return 0;
}
