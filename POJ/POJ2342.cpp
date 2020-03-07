#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 6005
vector<int> g[maxn];
int dp[2][maxn],a[maxn];
void dfs(int u,int f)
{
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=f)dfs(v,u);
    }
    int p=0,q=a[u];
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v!=f)
        {
            p+=max(dp[0][v],dp[1][v]);
            q+=dp[0][v];
        }
    }
    dp[0][u]=p,dp[1][u]=q;
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y);g[y].push_back(x);
    }
    dfs(1,0);
    printf("%d\n",max(dp[0][1],dp[1][1]));
    return 0;
}
