#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn];
int n,ans;
int sz[maxn];
void dfs(int u,int fa)
{
    sz[u]=1;
    for(int v : g[u])if(v!=fa)
        dfs(v,u),sz[u]+=sz[v];
    if(sz[u]%2==0 && fa!=-1)ans++;
}
main()
{
    scanf("%d",&n);
    if(n&1)return 0*puts("-1");
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,-1);
    printf("%d\n",ans);
    return 0;
}
