#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
const ll INF=1e16L;
vector<pii> g[maxn<<3];
int n,k,s;
ll dis[maxn<<3];
int nd[2][maxn<<2],tot;
struct P
{
    int u;ll d;
    bool operator < (const P& rhs)const{return d>rhs.d;}
};
priority_queue<P> pq;
bool vis[maxn<<3];
void add(int u,int v,int w)
{
    g[u].push_back(pii(v,w));
}
void build(int l,int r,int o,int id)
{
    nd[id][o]=++tot;
    if(l==r)
    {
        if(!id)add(nd[id][o],l,0);
        else add(l,nd[id][o],0);
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,o<<1,id);
    build(m+1,r,o<<1|1,id);
    if(!id)
    {
        add(nd[id][o],nd[id][o<<1],0);
        add(nd[id][o],nd[id][o<<1|1],0);
    }
    else
    {
        add(nd[id][o<<1],nd[id][o],0);
        add(nd[id][o<<1|1],nd[id][o],0);
    }
}
void update(int l,int r,int o,int ql,int qr,int v,int w,int id)
{
    if(ql<=l && r<=qr)
    {
        if(!id)add(v,nd[id][o],w);
        else add(nd[id][o],v,w);
        return ;
    }
    int m=(l+r)>>1;
    if(qr<=m)update(l,m,o<<1,ql,qr,v,w,id);
    else if(ql>m)update(m+1,r,o<<1|1,ql,qr,v,w,id);
    else update(l,m,o<<1,ql,qr,v,w,id),update(m+1,r,o<<1|1,ql,qr,v,w,id);
}
main()
{
    scanf("%d%d%d",&n,&k,&s);
    tot=n;
    build(1,n,1,0);
    build(1,n,1,1);
    for(int i=1;i<=k;i++)
    {
        int type,v;
        scanf("%d%d",&type,&v);
        if(type==1)
        {
            int u,w;scanf("%d%d",&u,&w);
            add(v,u,w);
        }
        else
        {
            int l,r,w;scanf("%d%d%d",&l,&r,&w);
            update(1,n,1,l,r,v,w,type-2);
        }
    }
    for(int i=1;i<=tot;i++)dis[i]=INF;
    dis[s]=0;
    pq.push({s,0ll});
    while(!pq.empty())
    {
        P t=pq.top();pq.pop();
        if(vis[t.u])continue;
        vis[t.u]=1;
        for(pii v : g[t.u])
        {
            if(dis[v.F]>dis[t.u]+v.S)
            {
                dis[v.F]=dis[t.u]+v.S;
                pq.push({v.F,dis[v.F]});
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",dis[i]==INF ? -1 : dis[i]);
    return 0;
}
