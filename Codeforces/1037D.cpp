#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
vector<int> g[maxn];
int n,dep[maxn],a[maxn],t[maxn],p[maxn];
void dfs(int u,int fa)
{
    for(int v : g[u])if(v!=fa)
    {
        p[v]=u,dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),t[a[i]]=i;
    dfs(1,0);
    bool flag=1;
    for(int i=1;i<n;i++)
        if(dep[a[i]]>dep[a[i+1]] || t[p[a[i]]]>t[p[a[i+1]]]){flag=0;break;}
    puts(flag ? "YES" : "NO");
    return 0;
}
