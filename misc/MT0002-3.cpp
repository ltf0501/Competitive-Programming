#include<bits/stdc++.h>
using namespace std;
#define maxn 2510
const int mod=1e9+7;
vector<int> g[maxn];
int ans=0;
int deg[maxn],d[maxn];
int n,m;
void dfs(int u,int fa,int cnt)
{
    if(deg[u]!=d[++cnt])return ;
    if(cnt==m){ans=(ans+1)%mod;return ;}
    for(int v : g[u])if(v!=fa)
        dfs(v,u,cnt);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n-1;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        deg[x]++,deg[y]++;
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i=1;i<=m;i++)scanf("%d",&d[i]);
    for(int i=1;i<=n;i++)dfs(i,0,0);
    printf("%d\n",ans);
    return 0;
}
