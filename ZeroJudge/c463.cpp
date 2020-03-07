#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
vector<int> g[maxn];
bool notroot[maxn];
int d[maxn];
int dfs(int u)
{
    if(!g[u].size())return 0;
    int ret=0;
    for(int v : g[u])ret=max(ret,dfs(v));
    return d[u]=ret+1;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int k;scanf("%d",&k);
        while(k--)
        {
            int x;scanf("%d",&x);
            notroot[x]=1;
            g[i].push_back(x);
        }
    }
    int t;
    for(int i=1;i<=n;i++)if(!notroot[i]){t=i;break;}
    printf("%d\n",t);
    dfs(t);
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=d[i];
    printf("%lld\n",ans);
    return 0;
}
