#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define pii pair<double,double>
#define F first
#define S second
double dis(pii a,pii b)
{
    return (a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S);
}
int n,m,s,v;
vector<int> g[maxn];
pii a[maxn],b[maxn];
int ans;
int match[maxn];
bool vis[maxn];
bool dfs(int u)
{
    vis[u]=1;
    for(int v : g[u])if(!vis[match[v]])
    {
        if(!match[v] || dfs(match[v]))
        {
            if(!match[v])ans++;
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
main()
{
    while(~scanf("%d%d",&n,&m))
    {
        scanf("%d%d",&s,&v);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++)cin>>a[i].F>>a[i].S;
        for(int i=1;i<=m;i++)cin>>b[i].F>>b[i].S;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
            if(v*v*s*s>=dis(a[i],b[j]))g[i].push_back(j);
        memset(match,0,sizeof(match));
        ans=0;
        for(int i=1;i<=n;i++)
        {
            dfs(i);
            memset(vis,0,sizeof(vis));
        }
        printf("%d\n",n-ans);
    }
    return 0;
}
