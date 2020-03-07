#include<bits/stdc++.h>
using namespace std;
#define maxn 10000+10
int dfs_clock,cnt;
int pre[maxn],low[maxn],n,m;
bool iscut[maxn];
vector<int> g[maxn];
int dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    int ch=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!pre[v])
        {
            ch++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowu>=pre[u])iscut[u]=1,cnt++;
        }
        else if(pre[v]<pre[u] && v!=fa)
        {
            lowu=min(lowu,pre[v]);
        }
    }
    if(fa<0 && ch==1)iscut[u]=0,cnt--;
    return low[u]=lowu;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)g[i].clear();
        dfs_clock=cnt=0;
        memset(pre,0,sizeof(pre));
        memset(iscut,false,sizeof(iscut));
        for(int i=0;i<m;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            g[a].push_back(b);g[b].push_back(a);
        }
        dfs(1,-1);
        //for(int i=0;i<n;i++)printf("%d ",low[i]);puts("");
        printf("%d\n",cnt);
        if(!cnt)puts("0");
        else
        {
            for(int i=1;i<=n;i++)if(iscut[i])printf("%d ",i);puts("");
        }
    }
    return 0;
}
