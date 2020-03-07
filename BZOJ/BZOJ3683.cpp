#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
vector<int> g[maxn];
ll tot[maxn],b[maxn];
int sz[maxn],maxson[maxn],pa[maxn],top[maxn];
int in[maxn],out[maxn],dfs_clock;
int n,q;
struct BIT
{
    ll bit[maxn];
    void add(int x,ll d){for(int i=x;i<=n;i+=i&-i)bit[i]+=d;}
    ll query(int x)
    {
        ll ret=0;
        for(int i=x;i;i-=i&-i)ret=max(ret,bit[i]);
        return ret;
    }
}bit1,bit2;
void dfs1(int u)
{
    sz[u]=1;
    int mxer=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        dfs1(v);
        tot[u]+=1ll*sz[u]*sz[v];
        sz[u]+=sz[v];
        if(sz[v]>sz[mxer])mxer=v;
    }
    maxson[u]=mxer;
}
void dfs2(int u,int tp)
{
    top[u]=tp;in[u]=++dfs_clock;
    if(maxson[u])dfs2(maxson[u],tp);
    for(int i=0;i<g[u].size();i++)
        if(g[u][i]!=maxson[u])dfs2(g[u][i],g[u][i]);
    out[u]=dfs_clock;
}
void modify(int id,ll k)
{
    while(id)
    {
        bit1.add(in[top[id]],k),bit1.add(in[id],-k),id=top[id];
        b[pa[id]]+=1ll*k*(sz[pa[id]]-sz[id]),id=pa[id];
    }
}
ll query(int x)
{
    ll ans=b[x];
    ans+=1ll*(sz[x]-sz[maxson[x]])*bit1.query(in[x]);
    ans+=bit2.query(in[x])*tot[x];
    return ans;
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&pa[i]);
        g[pa[i]].push_back(i);
    }
    dfs1(1);
    dfs2(1,1);
    for(int i=1;i<=n;i++)
    {
        ll x;scanf("%lld",&x);
        modify(i,x);
        b[i]+=1ll*(sz[i]-1)*x;
    }
    //for(int i=1;i<=n;i++)printf("%lld ",b[i]);puts("");
    while(q--)
    {
        char c[2];scanf("%s",c);
        int x;scanf("%d",&x);
        if(c[0]=='Q')printf("%.9f\n",(double)query(x)/(double)tot[x]);
        else
        {
            ll y;scanf("%lld",&y);
            if(c[0]=='S')
            {
                modify(x,y);
                b[x]+=y*(sz[x]-1);
            }
            else
            {
                modify(x,y*sz[x]);
                bit2.add(in[x],2*y),bit2.add(out[x]+1,-2*y);
            }
        }
        //for(int i=1;i<=n;i++)printf("%lld ",b[i]);puts("");
    }
    return 0;
}
/*
4 15
1 2 2
0 -6 3 0
S 2 -5
M 3 8
S 1 -1
M 4 7
M 3 2
Q 1
*/
