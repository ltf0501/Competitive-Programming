#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
vector<int> g[maxn];
ll dp[maxn];
ll a[maxn],b[maxn];
int n;
bool flag=0;
struct line
{
    mutable ll k,m,p;
    line(int k,int m,int p):k(k),m(m),p(p){}
    bool operator < (const line &b)const
    {
        return flag ? p<b.p : k<b.k;
    }
    //void prints(){printf("%lldx+%lld\n",k,m);}
};
struct Convex_Hull : multiset<line>
{
    const ll INF=LLONG_MAX;
    ll d(ll a,ll b){return a/b-((a^b)<0 && a%b);}
    bool sect(iterator x,iterator y)
    {
        if(y==end()){x->p=INF;return 0;}
        if(x->k==y->k)x->p=(x->m>y->m ? INF : -INF);
        else x->p=d(y->m-x->m,x->k-y->k);
        return x->p>=y->p;
    }
    void add(ll k,ll m)
    {
        auto z=insert(line(k,m,0)),y=z++,x=y;
        while(sect(y,z))z=erase(z);
        if(x!=begin() && sect(--x,y))sect(x,y=erase(y));
        while((y=x)!=begin() && (--x)->p>=y->p)sect(x,erase(y));
    }
    ll query(ll x)
    {
        flag=1;
        auto s=lower_bound(line(0,0,x));
        //printf("ans: %lldx+%lld\n",s->k,s->m);
        flag=0;
        return (s->k)*x+(s->m);
    }
    void print()
    {
        auto x=begin();
        while(x!=end())printf("%lldx+%lld %lld\n",x->k,x->m,x->p),x++;
    }
};
int sz[maxn];
void dfs1(int u,int fa)
{
    sz[u]=1;
    for(int v : g[u])if(v!=fa)
        dfs1(v,u),sz[u]+=sz[v];
}
void dfs2(int u,int fa,Convex_Hull &cur)
{
    int mx=-1,big=-1;
    bool leaf=1;
    for(int v : g[u])if(v!=fa && sz[v]>mx)
        mx=sz[v],big=v,leaf=0;
    if(big>=0)dfs2(big,u,cur);
    for(int v : g[u])if(v!=fa && v!=big)
    {
        Convex_Hull tmp;
        dfs2(v,u,tmp);
        for(auto s : tmp)cur.add(s.k,s.m);
    }
    //printf("%d:\n",u);
    //cur.print();
    if(!leaf)dp[u]=-cur.query(a[u]);
    else dp[u]=0;
    cur.add(-b[u],-dp[u]);
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs1(1,0);
    Convex_Hull root;
    dfs2(1,0,root);
    for(int i=1;i<=n;i++)printf("%lld ",dp[i]);
    return 0;
}
