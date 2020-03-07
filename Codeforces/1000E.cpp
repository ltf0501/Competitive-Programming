#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define pii pair<int,int>
#define F first
#define S second
vector<pii> edge;
vector<int> g[maxn],bcc_g[maxn];
int n,m;
int bccno[maxn],bcc_cnt,dfs_clock,in[maxn];
stack<int> s;
int to(int u,int id){return u^edge[id].F^edge[id].S;}
int dfs1(int u,int fa)
{
    s.push(u);
    int lowu=in[u]=++dfs_clock;
    for(int id : g[u])
    {
        int v=to(u,id);
        if(v==fa)continue;
        if(!in[v])lowu=min(lowu,dfs1(v,u));
        else lowu=min(lowu,in[v]);
    }
    if(lowu==in[u])
    {
        bcc_cnt++;
        while(1)
        {
            int x=s.top();s.pop();
            bccno[x]=bcc_cnt;
            if(x==u)break;
        }
    }
    return lowu;
}
int mx,pos;
void dfs2(int u,int fa,int dep)
{
    if(dep>mx)mx=dep,pos=u;
    for(int v : bcc_g[u])if(v!=fa)
        dfs2(v,u,dep+1);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        edge.push_back(pii(x,y));
        g[x].push_back(i),g[y].push_back(i);
    }
    dfs1(1,0);
    //puts("XD");
    for(pii e : edge)
    {
        int u=e.F,v=e.S;
        if(bccno[u]!=bccno[v])bcc_g[bccno[u]].push_back(bccno[v]),bcc_g[bccno[v]].push_back(bccno[u]);
    }
    mx=-1;
    dfs2(1,0,0);
    mx=-1;
    dfs2(pos,0,0);
    printf("%d\n",mx);
    return 0;
}
