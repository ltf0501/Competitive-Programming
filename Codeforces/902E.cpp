#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
#define ll long long
vector<int> g[maxn];
int n,m,q;
vector<pii> que[maxn];
int vis[maxn],l[maxn];
ll ans[maxn];
stack<int> S;
void dfs(int u,int fa)
{
    S.push(u);
    vis[u]=1;
    for(int v : g[u])if(v!=fa)
    {
        if(!vis[v])dfs(v,u);
        else if(vis[v]==1)
        {
            int mi=maxn,mx=0;
            while(!S.empty())
            {
                int w=S.top();S.pop();
                mi=min(mi,w);
                mx=max(mx,w);
                if(w==v)break;
            }
            l[mx]=mi;
        }
    }
    if(!S.empty() && S.top()==u)S.pop();
    vis[u]=2;
}
ll sum[maxn<<2],tg[maxn<<2];
void push_up(int o){sum[o]=sum[o<<1]+sum[o<<1|1];}
void push_down(int l,int r,int o)
{
    if(!tg[o])return ;
    int m=(l+r)>>1;
    sum[o<<1]+=(m-l+1)*tg[o],sum[o<<1|1]+=(r-m)*tg[o];
    tg[o<<1]+=tg[o],tg[o<<1|1]+=tg[o];
    tg[o]=0;
}
void update(int l,int r,int o,int ql,int qr,int d)
{
    if(ql<=l && r<=qr){sum[o]+=(ll)(r-l+1)*(ll)d,tg[o]+=(ll)d;return ;}
    push_down(l,r,o);
    int m=(l+r)>>1;
    if(ql<=m)update(l,m,o<<1,ql,qr,d);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,d);
    push_up(o);
}
ll query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return sum[o];
    push_down(l,r,o);
    ll ret=0;
    int m=(l+r)>>1;
    if(ql<=m)ret+=query(l,m,o<<1,ql,qr);
    if(qr>m)ret+=query(m+1,r,o<<1|1,ql,qr);
    return ret;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs(i,0);
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,l[i]);
        l[i]=mx+1;
    }
    ///for(int i=1;i<=n;i++)printf("%d ",l[i]);puts("");
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int l,r;scanf("%d%d",&l,&r);
        que[r].push_back(mkp(i,l));
    }
    for(int i=1;i<=n;i++)
    {
        update(1,n,1,l[i],i,1);
        ///for(int i=1;i<=n;i++)printf("%d ",query(1,n,1,i,i));puts("");
        for(pii v : que[i])ans[v.F]=query(1,n,1,v.S,i);
    }
    for(int i=1;i<=q;i++)printf("%I64d\n",ans[i]);
    return 0;
}
