#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define ALL(v) v.begin(),v.end()
const ll INF=1e18;
struct P
{
    ll x,y;
    int id;
    bool operator < (const P& b)const
    {
        if(x!=b.x)return x<b.x;
        return y<b.y;
    }
};
struct edge
{
    int u,v;ll w;
    bool operator < (const edge& b)const{return w<b.w;}
};
P a[maxn];
int x,y,n;
vector<edge> e;
vector<int> v;
int c[maxn];
#define pii pair<ll,int>
#define F first
#define S second
pii bit[maxn];
void add(int x,pii d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]=min(bit[i],d);
}
pii query(int x)
{
    pii ret=pii(INF,0);
    for(int i=x;i;i-=i&-i)ret=min(ret,bit[i]);
    return ret;
}
ll dis(P a,P b){return abs(a.x-b.x)+abs(a.y-b.y);}
void gao()
{
    v.clear();
    for(int i=1;i<=n;i++)v.push_back(a[i].y-a[i].x);
    sort(ALL(v));
    v.resize(unique(ALL(v))-v.begin());
    for(int i=1;i<=n;i++)c[i]=lower_bound(ALL(v),a[i].y-a[i].x)-v.begin()+1;
    for(int i=1;i<=n;i++)bit[i]=pii(INF,0);
    for(int i=n;i>=1;i--)
    {
        pii x=query(n-c[i]+1);
        if(x.S)e.push_back((edge){a[i].id,a[x.S].id,dis(a[i],a[x.S])});
        add(n-c[i]+1,pii(a[i].x+a[i].y,i));
    }
}
int p[maxn],sz[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
ll Union(int u,int v,ll d)
{
    int a=finds(u),b=finds(v);
    if(a==b)return 0;
    if(sz[a]>sz[b])swap(a,b);
    sz[b]+=sz[a],p[a]=b;
    return d;
}
ll kruskal()
{
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    ll ans=0;
    for(edge x : e)
    {
        int u=x.u,v=x.v;ll d=x.w;
        ans+=Union(u,v,d);
    }
    return ans;
}
main()
{
    scanf("%d%d%d",&x,&y,&n);
    for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].y),a[i].id=i;
    sort(a+1,a+n+1);
    gao();
    for(int i=1;i<=n;i++)swap(a[i].x,a[i].y);
    sort(a+1,a+n+1);
    gao();
    for(int i=1;i<=n;i++)a[i].y=-a[i].y;
    sort(a+1,a+n+1);
    gao();
    for(int i=1;i<=n;i++)swap(a[i].x,a[i].y),a[i].x=-a[i].x,a[i].y=-a[i].y;
    sort(a+1,a+n+1);
    gao();
    //for(edge x : e)printf("%d %d\n",x.u,x.v);
    printf("%lld\n",kruskal());
    return 0;
}
