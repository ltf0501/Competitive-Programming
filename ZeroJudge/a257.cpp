#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
vector<int> g[maxn];
int n,a[maxn];
int in[maxn],dfs_clock;
bool iscut[maxn];
void init()
{
    memset(iscut,false,sizeof(iscut));
    memset(in,0,sizeof(in));
    dfs_clock=0;
}
int dfs(int u,int fa)
{
    int lowu=in[u]=++dfs_clock;
    int ch=0;
    for(int v : g[u])
    {
        if(!in[v])
        {
            ch++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=in[u])iscut[u]=1;
        }
        else if(in[v]<in[u] && v!=fa)
        {
            lowu=min(lowu,in[v]);
        }
    }
    if(fa<0 && ch==1)iscut[u]=0;
    return lowu;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)g[i].clear();
        init();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
        {
            if(__gcd(a[i],a[j])>1)
                g[i].push_back(j),g[j].push_back(i);
        }
        for(int i=1;i<=n;i++)
            if(!in[i])dfs(i,-1);
        int ans=0;
        for(int i=1;i<=n;i++)
            if(iscut[i])ans++;
        printf("%d\n",ans);
    }
    return 0;
}
