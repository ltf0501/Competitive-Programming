#include<bits/stdc++.h>
using namespace std;
#define maxn 200000+5
#define ll long long
int sz[maxn],c[maxn][5];
int n,k;
vector<int> g[maxn];
ll ans=0;
void dfs(int u,int fa)
{
    sz[u]=1,c[u][0]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        dfs(v,u);
        sz[u]+=sz[v];
        for(int a=0;a<k;a++)for(int b=0;b<k;b++)
        {
            if(a+b+1>k)ans+=2ll*c[u][a]*c[v][b];
            else ans+=1ll*c[u][a]*c[v][b];
        }
        for(int j=0;j<k;j++)c[u][(j+1)%k]+=c[v][j];
        ans+=1ll*(n-sz[u])*c[v][k-1];
    }
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n-1;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,0);
    printf("%I64d\n",ans);
    return 0;
}
