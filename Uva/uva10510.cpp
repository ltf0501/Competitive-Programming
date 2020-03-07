#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
vector<int> g[maxn];
int pre[maxn],low[maxn],fa[maxn],dfs_clock;
int scc_cnt,sccno[maxn];
int cnt[maxn];
stack<int> s;
bool gao(int x,int p)
{
    while(x!=p)
    {
        if(++cnt[x]>=2)return 0;
        x=fa[x];
    }
    return 1;
}
bool dfs(int u)
{
    low[u]=pre[u]=++dfs_clock;
    s.push(u);
    for(int v : g[u])
    {
        if(!pre[v])
        {
            fa[v]=u;
            if(!dfs(v))return 0;
            low[u]=min(low[u],low[v]);
        }
        else if(!sccno[v])
        {
            if(!gao(u,v))return 0;
            low[u]=min(low[u],pre[v]);
        }
    }
    if(low[u]==pre[u])
    {
        if(++scc_cnt>=2)return 0;
        while(1)
        {
            int x=s.top();s.pop();
            sccno[x]=scc_cnt;
            if(x==u)break;
        }
    }
    return 1;
}
void init(int n)
{
    for(int i=0;i<n;i++)g[i].clear();
    dfs_clock=0,scc_cnt=0;
    memset(pre,0,sizeof(pre));
    memset(sccno,0,sizeof(sccno));
    memset(cnt,0,sizeof(cnt));
    while(!s.empty())s.pop();
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        init(n);
        for(int i=1;i<=m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            g[x].push_back(y);
        }
        bool ok=1;
        for(int i=0;i<n;i++)
            if(!pre[i] && !dfs(i)){ok=0,puts("NO");break;}
        if(ok)puts("YES");
    }
    return 0;
}
