#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define ll long long
ll a[maxn];
int n;
vector<int> g[maxn];
bool vis[maxn];
int out[maxn],dfs_clock;
vector<int> v;
void dfs(int u)
{
    dfs_clock++;
    vis[u]=1;
    for(int v : g[u])
        if(!vis[v])dfs(v);
    out[u]=dfs_clock;
    v.push_back(u);
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
    {
        if(a[i]*2==a[j] || a[j]*3==a[i])g[j].push_back(i);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs(i);
    for(int s : v)printf("%lld ",a[s]);
    return 0;
}
