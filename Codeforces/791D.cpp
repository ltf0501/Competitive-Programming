#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int dp[5][maxn],sz[maxn];
ll ans;
int n,k;
vector<int> g[maxn];
void dfs(int u,int fa)
{
    sz[u]=1;
    for(int v : g[u])if(v!=fa)
    {
        dfs(v,u);
        sz[u]+=sz[v];
        for(int i=0;i<k;i++)for(int j=0;j<k;j++)
            dp[(i+j+1)%k][u]+=dp[j][v];
    }
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)ans+=1ll*sz[i]*(n-sz[i]);
    for(int i=1;i<=n;i++)for(int j=1;j<k;j++)
        ans+=1ll*dp[j][i]*(k-j);
    printf("%lld\n",ans);
    return 0;
}
