#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
vector<int> g[maxn];
int n,s,t;
int p[maxn],sz[maxn];
void dfs(int u,int fa)
{
    p[u]=fa,sz[u]=1;
    for(int v : g[u])if(v!=fa)
    {
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
main()
{
    scanf("%d%d%d",&n,&s,&t);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(s,-1);
    //for(int i=1;i<=n;i++)printf("%d ",sz[i]);puts("");
    ll ans=1ll*n*(n-1);
    int cur=t;
    while(p[cur]!=s)cur=p[cur];
    //printf("%d\n",cur);
    ans-=1ll*(n-sz[cur])*sz[t];
    printf("%lld\n",ans);
    return 0;
}
