#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 10000+5

vector<int> g[maxn];
int n;
int dp[maxn][2];
int dfs(int u,int fa,int j)
{
    int ans=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        ans+=dfs(v,u,1);
    }
    if(j || fa==0)
    {
        int sum=0;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(v==fa)continue;
            sum+=dfs(v,u,0);
        }
        ans=min(ans,sum);
    }
    return ans;
}
main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        g[a].push_back(b);g[b].push_back(a);
    }
    int ans=dfs(1,0,0);
    printf("%d\n",ans);
    return 0;
}
