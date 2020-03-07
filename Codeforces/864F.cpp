#include<bits/stdc++.h>
using namespace std;
#define maxn 3010
#define maxq 400010
struct P{int to,k,id;};
vector<P> que[maxn];
vector<int> g1[maxn],g2[maxn],g3[maxn];
bool vis[maxn];
int ans[maxq];
int n,m,q;
void dfs1(int u)
{
    if(vis[u])return ;
    vis[u]=1;
    for(int v : g2[u])dfs1(v);
}
int stk[maxn];
vector<P> qq[maxn];
void dfs2(int u,int d)
{
    if(vis[u])return ;
    vis[u]=1;
    stk[d]=u;
    for(auto ss : qq[u])
    {
        if(ss.k>d)ans[ss.id]=-1;
        else ans[ss.id]=stk[d-ss.k+1];
    }
    for(int v : g3[u])dfs2(v,d+1);
}
main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g1[x].push_back(y),g2[y].push_back(x);
    }
    for(int i=1;i<=q;i++)
    {
        int x,y,k;scanf("%d%d%d",&x,&y,&k);
        que[y].push_back({x,k,i});
    }
    for(int i=1;i<=n;i++)
    {
        dfs1(i);
        for(int j=1;j<=n;j++)if(j!=i)
        {
            int t=maxn;
            for(int k : g1[j])if(vis[k] && k<t)t=k;
            if(t!=maxn)g3[t].push_back(j);
        }
        /*
        printf("now=%d:\n",i);
        for(int j=1;j<=n;j++)
        {
            printf("%d: ",j);
            for(int k=0;k<3;k++)printf("%d ",anc[k][j]);puts("");
        }
        puts("");
        */
        memset(vis,0,sizeof(vis));
        for(auto ss : que[i])qq[ss.to].push_back({i,ss.k,ss.id});
        dfs2(i,1);
        //for(int j=1;j<=n;j++)printf("%d ",vis[j]);puts("");
        for(int j=1;j<=n;j++)qq[j].clear(),g3[j].clear();
        memset(vis,0,sizeof(vis));
    }
    for(int i=1;i<=q;i++)if(!ans[i])ans[i]=-1;
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}
/*
7 7 5
1 2
2 3
1 3
3 4
4 5
5 3
4 6
1 4 2
2 6 1
1 7 3
1 3 2
1 3 5
*/
