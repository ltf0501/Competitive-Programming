#include<bits/stdc++.h>
using namespace std;
const int maxn=505,maxm=100010;
#define pii pair<int,int>
#define F first
#define S second
vector<int> g[maxn];
vector<pii> edge;
int vis[maxn];
bool check[maxm];
bool dfs1(int u)
{
    vis[u]=-1;
    for(int i : g[u])
    {
        int v=edge[i].S;
        if(!vis[v])
        {
            if(dfs1(v)){check[i]=1;return 1;}
        }
        else if(vis[v]==-1)
        {
            check[i]=1;
            return 1;
        }
    }
    vis[u]=1;
    return 0;
}
bool dfs2(int u,int k)
{
    vis[u]=-1;
    for(int i : g[u])if(i!=k)
    {
        int v=edge[i].S;
        if(!vis[v])
        {
            if(dfs2(v,k))return 1;
        }
        else if(vis[v]==-1)return 1;
    }
    vis[u]=1;
    return 0;
}
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(i);
        edge.push_back(pii(x,y));
    }
    bool flag=1;
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            int k=dfs1(i);
            if(k){flag=0;break;}
        }
    if(flag)return 0*puts("YES");
    ///for(int i=0;i<m;i++)if(check[i])printf("%d ",i);puts("");
    for(int i=0;i<m;i++)if(check[i])
    {
        memset(vis,0,sizeof(vis));
        flag=1;
        for(int j=1;j<=n;j++)
            if(!vis[j])
            {
                int k=dfs2(j,i);
                if(k){flag=0;break;}
            }
        if(flag)return 0*puts("YES");
    }
    return 0*puts("NO");
}
