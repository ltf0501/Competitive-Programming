#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define pii pair<int,int>
#define F first
#define S second
vector<int> g[maxn];
pii a[maxn],b[maxn];
int n,m,ans;
int match[maxn];
bool vis[maxn];
double dis(pii a,pii b)
{
    return sqrt((a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S));
}
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
    int t;scanf("%d",&t);
    bool ss=0;
    while(t--)
    {
        if(ss)puts("");
        ss=1;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)g[i].clear();
        for(int i=1;i<=n;i++)scanf("%d%d",&a[i].F,&a[i].S);
        for(int i=1;i<=m;i++)scanf("%d%d",&b[i].F,&b[i].S);
        for(int i=1;i<n;i++)for(int j=1;j<=m;j++)
            if((dis(a[i],b[j])+dis(a[i+1],b[j])<=2*dis(a[i],a[i+1])))g[j].push_back(i);
        memset(match,0,sizeof(match));
        ans=0;
        for(int i=1;i<=m;i++)
        {
            dfs(i);
            memset(vis,0,sizeof(vis));
        }
        printf("%d\n",ans+n);
        for(int i=1;i<n;i++)
        {
            printf("%d %d ",a[i].F,a[i].S);
            if(match[i])
            {
                int j=match[i];
                printf("%d %d ",b[j].F,b[j].S);
            }
        }
        printf("%d %d\n",a[n].F,a[n].S);
    }
    return 0;
}

