#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define ALL(v) v.begin(),v.end()
int n,q;
vector<pii> g[maxn];
int ans[maxn],sz[maxn],mx[maxn];
bool vis[maxn];
vector<int> now;
vector<ll> dis;
ll d[maxn];
struct Q{ll d;int id;};
vector<Q> que[maxn];
void get_cen(int u)
{
    vis[u]=1,sz[u]=1,mx[u]=0;
    now.push_back(u);
    for(pii v : g[u])if(!vis[v.F])
    {
        get_cen(v.F);
        sz[u]+=sz[v.F],mx[u]=max(mx[u],sz[v.F]);
    }
}
void get_dis(int u,int fa)
{
    now.push_back(u);
    dis.push_back(d[u]);
    for(pii v : g[u])if(v.F!=fa && !vis[v.F])
    {
        d[v.F]=d[u]+v.S;
        get_dis(v.F,u);
    }
}
void cal(int u,ll val,int flag)
{
    dis.clear();d[u]=val;
    get_dis(u,-1);
    sort(ALL(dis));
    //printf("%d %d: ",u,flag);
    //for(ll s : dis)printf("%lld ",s);puts("");
    for(int v : now)
    {
        ll dd=d[v];
        for(Q q : que[v])
        {
            ll k=q.d-dd;
            ans[q.id]+=flag*(upper_bound(ALL(dis),k)-dis.begin());
        }
    }
    now.clear();
}
void dfs(int u)
{
    get_cen(u);
    int s=now.size(),cen=-1;
    for(int w : now)
    {
        if(max(mx[w],s-sz[w])<=s/2)cen=w;
        vis[w]=0;
    }
    now.clear();
    cal(cen,0,1);
    vis[cen]=1;
    for(pii v : g[cen])if(!vis[v.F])
    {
        cal(v.F,v.S,-1);
        dfs(v.F);
    }
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        g[x].push_back(pii(y,d)),g[y].push_back(pii(x,d));
    }
    for(int i=1;i<=q;i++)
    {
        int v;ll d;scanf("%d%lld",&v,&d);
        que[v].push_back({d,i});
    }
    dfs(1);
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}
/*
4 6
1 2 3
2 3 10
3 4 51
1 2
1 10
3 30
3 51
2 60
2 61
*/
