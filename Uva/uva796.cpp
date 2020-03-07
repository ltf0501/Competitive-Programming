#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define maxn 2000000+10
#define F first
#define S second
pii mk(int x,int y)
{
    if(x>y)swap(x,y);
    return pii(x,y);
}
vector<pii> ans;
vector<int> g[maxn];
int pre[maxn],dfs_clock;
int dfs(int u,int fa)
{
    int lowu=pre[u]=++dfs_clock;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!pre[v])
        {
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>pre[u])ans.push_back(mk(v,u));
        }
        else if(pre[v]<pre[u] && v!=fa)lowu=min(lowu,pre[v]);
    }
    return lowu;
}
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        ans.clear();
        dfs_clock=0;
        for(int i=0;i<n;i++)g[i].clear();
        memset(pre,0,sizeof(pre));
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            int m;
            scanf(" (%d)",&m);
            while(m--)
            {
                int y;
                scanf("%d",&y);
                g[x].push_back(y);
            }
        }
        for(int i=0;i<n;i++)
            if(!pre[i])dfs(i,-1);
        sort(ans.begin(),ans.end());
        printf("%d critical links\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d - %d\n",ans[i].F,ans[i].S);
        puts("");
    }
    return 0;
}
/*
2
0 (1) 1
1 (1) 0
*/
