#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
#define ll long long
short d[maxn][maxn];
vector<int> g[maxn];
int dfs(int root,int u,int fa,int dep)
{
    d[root][dep]++;
    int ret=dep;
    for(int v : g[u])if(v!=fa)
        ret=max(ret,dfs(root,v,u,dep+1));
    return ret;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int maxd=0;
        for(int u : g[i])
        {
            fill(d[u],d[u]+n,0);
            maxd=max(maxd,dfs(u,u,i,0));
        }
        for(int j=0;j<=maxd;j++)
        {
            ll a=0,b=0,c=0;
            for(int u : g[i])
            {
                a+=(ll)d[u][j];
                b+=(ll)d[u][j]*(ll)d[u][j];
                c+=(ll)d[u][j]*(ll)d[u][j]*(ll)d[u][j];
            }
            ans+=(a*a*a-3*a*b+2*c)/6;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
