#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
struct U{int id,h,v;};
struct Q{int u,v,d;};
int n,q,SZ;
vector<multiset<int> > s[maxn];
vector<int> qq[maxn];
map<int,ll> mp[maxn];
struct E{int x,y,h,v;};
int to(int x,int id){return x^edge[id].x^edge[id].y;}
vector<E> edge;
vector<int> g[maxn],gg[maxn];
int p[maxn],dep[maxn],sz[maxn],top[maxn];
struct BIT
{
    vector<ll> bit;
    int sz;
    void init(int n)
    {
        sz=n,bit.resize(n+1);
    }
    void add(int x,int d)
    {
        for(int i=x;i<=sz;i+=i&-i)bit[i]+=d;
    }
    ll query(int x)
    {
        ll res=0;
        for(int i=x;i;i-=i&-i)res+=bit[i];
        return res;
    }
};
void build(int u,int fa,int d)
{
    p[u]=fa,dep[u]=d;
    if(!top[u])top[u]=u,sz[u]=1;
    s[u].resize(maxn*2);
    for(int id : g[u])
    {
        int v=to(id);
        if(v==fa)continue ;
        if(sz[top[u]]+1<SZ)
        {
            gg[u].push_back(id);
            sz[top[u]]++,top[v]=top[u];
            s[v]=s[u];
            int h=g[u][id].h,val=g[u][id].v;
            s[v][h].insert(val);
            mp[v][h]+=val;
        }
    }
    build(v,u,d+1);
}
void dfs(int u,int h,int val)
{
    for(int id : gg[u])
    {
        int v=to(id);

    }
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int x,y,h,v;scanf("%d%d%d%d",&x,&y,&h,&v);
        int m=edge.size();
        edge.push_back({x,y,h,v});
        g[x].push_back(m),g[y].push_back(m);
    }
    SZ=(int)sqrt(n+0.5);
    build(1,0,0);
    return 0;
}
