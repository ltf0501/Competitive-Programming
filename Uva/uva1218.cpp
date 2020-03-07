#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=10009;
vector<int>g[N];
int dp[N][3];

void dfs(int u,int fa)
{
    dp[u][0]=1;
    dp[u][1]=0;
    dp[u][2]=N;
    for(int i=0;i<g[u].size();i++)
    {
        if(g[u][i]!=fa)
        {
            dfs(g[u][i],u);
            dp[u][0]+=min(dp[g[u][i]][0],dp[g[u][i]][1]);
            dp[u][1]+=dp[g[u][i]][2];
        }
    }

    for(int i=0;i<g[u].size();i++)
    {
        if(g[u][i]!=fa)
            dp[u][2]=min(dp[u][2],dp[u][1]+dp[g[u][i]][0]-dp[g[u][i]][2]);
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int a,b;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        dfs(1,-1);
        printf("%d\n",min(dp[1][0],dp[1][2]));

        scanf("%d",&a);
        if(a==-1)break;
        for(int i=1;i<=n;i++)
            g[i].clear();
    }
    return 0;
}
