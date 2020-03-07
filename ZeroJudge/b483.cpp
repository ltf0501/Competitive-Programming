#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1e9;
#define maxn 100010
struct edge
{
    int x,y,id;
    ll d;
};
bool cmp(edge a,edge b){return a.d<b.d;}
vector<edge> E[20],edges;
struct Q
{
    int id,d;
}query[maxn];
int n,m,q;
ll ans[maxn],a[maxn];
int p[maxn],M[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void init()
{
    memset(ans,0,sizeof(ans));
    memset(a,0,sizeof(a));
    for(int i=0;i<20;i++)E[i].clear();
    edges.clear();
    for(int i=1;i<=n;i++)p[i]=i;
    memset(M,0,sizeof(M));
}
void clean(vector<edge>& edges)
{
    for(edge e : edges)
        p[e.x]=e.x,p[e.y]=e.y;
}
vector<edge> tmp;
void con(vector<edge>& edges,ll& val)//ÁYÂI
{
    clean(edges);
    sort(edges.begin(),edges.end(),cmp);
    tmp.clear();
    for(edge& e : edges)
    {
        int u=finds(e.x),v=finds(e.y);
        if(u!=v)
        {
            p[u]=v;
            tmp.push_back(e);
        }
    }
    clean(tmp);
    for(edge& e : tmp)
    {
        int u=finds(e.x),v=finds(e.y);
        if(u!=v && e.d!=-INF)
        {
            p[u]=v;
            val+=e.d;
        }
    }
    tmp.clear();
    for(edge& e : edges)
    {
        int u=finds(e.x),v=finds(e.y);
        if(u!=v)
        {
            tmp.push_back(e);
            M[e.id]=tmp.size()-1;
            tmp.back().x=p[e.x];
			tmp.back().y=p[e.y];
        }
    }
    edges=tmp;
}
void re(vector<edge>& edges)//§RÃä
{
    clean(edges);
    sort(edges.begin(),edges.end(),cmp);
    tmp.clear();
    for(edge& e : edges)
    {
        int u=finds(e.x),v=finds(e.y);
        if(u!=v)
        {
            p[u]=v;
            tmp.push_back(e);
            M[e.id]=tmp.size()-1;
        }
        else if(e.d==INF)
        {
            tmp.push_back(e),
            M[e.id]=tmp.size()-1;
        }
    }
    edges=tmp;
}

void cdq(int l,int r,int now,ll val)
{
    if(l==r)a[query[l].id]=query[l].d;
    for(edge& e : E[now])e.d=a[e.id];
    edges=E[now];
    int tmp=0;
    for(edge& e : E[now])M[e.id]=tmp++;
    if(l==r)
    {
        ans[l]=val;
        clean(edges);
        sort(edges.begin(),edges.end(),cmp);
        for(edge& e : edges)
        {
            int u=finds(e.x),v=finds(e.y);
            if(u==v)continue;
            p[u]=v;
            ans[l]+=e.d;
        }
        return ;
    }
    for(int i=l;i<=r;i++)edges[M[query[i].id]].d=-INF;
    con(edges,val);
    for(int i=l;i<=r;i++)edges[M[query[i].id]].d=INF;
    re(edges);
    E[now+1]=edges;
    int m=(l+r)>>1;
    cdq(l,m,now+1,val),cdq(m+1,r,now+1,val);
}
main()
{

    scanf("%d%d%d",&n,&m,&q);
    //init();
    for(int i=1;i<=m;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        E[0].push_back((edge){x,y,i,d});
        a[i]=d;
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        query[i]=(Q){x,y};
    }
    cdq(1,q,0,0);
    for(int i=1;i<=q;i++)
    {
        printf("%lld\n",ans[i]);
    }

    return 0;
}
