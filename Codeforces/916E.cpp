#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
int n,q,root=1;
vector<int> g[maxn];
int a[maxn],b[maxn];
int in[maxn],out[maxn],dfs_clock,dep[maxn];
int anc[18][maxn];
void dfs(int u,int fa,int d)
{
    in[u]=++dfs_clock;
    b[dfs_clock]=a[u];
    dep[u]=d;
    anc[0][u]=fa;
    for(int v : g[u])if(v!=fa)
        dfs(v,u,d+1);
    out[u]=dfs_clock;
}
void pre()
{
    for(int i=1;i<=17;i++)
        for(int j=1;j<=n;j++)anc[i][j]=anc[i-1][anc[i-1][j]];
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x];
    return anc[0][x];
}
int get(int l,int x)
{
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][x],l))
        x=anc[i][x];
    return x;
}
ll sum[maxn<<2],tg[maxn<<2];
void push_up(int o){sum[o]=sum[o<<1]+sum[o<<1|1];}
void push_down(int l,int r,int o)
{
    if(!tg[o])return ;
    int m=(l+r)>>1;
    sum[o<<1]+=tg[o]*(m-l+1),sum[o<<1|1]+=tg[o]*(r-m);
    tg[o<<1]+=tg[o],tg[o<<1|1]+=tg[o];
    tg[o]=0;
}
void build(int l,int r,int o)
{
    if(l==r){sum[o]=b[l];return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int ql,int qr,int v)
{
    if(ql<=l && r<=qr){sum[o]+=1ll*v*(r-l+1),tg[o]+=v;return ;}
    int m=(l+r)>>1;
    push_down(l,r,o);
    if(ql<=m)update(l,m,o<<1,ql,qr,v);
    if(qr>m)update(m+1,r,o<<1|1,ql,qr,v);
    push_up(o);
}
ll query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return sum[o];
    ll ret=0;
    int m=(l+r)>>1;
    push_down(l,r,o);
    if(ql<=m)ret+=query(l,m,o<<1,ql,qr);
    if(qr>m)ret+=query(m+1,r,o<<1|1,ql,qr);
    return ret;
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    dfs(1,0,0);out[0]=dfs_clock;
    pre();
    build(1,n,1);
    while(q--)
    {
        int type;scanf("%d",&type);
        if(type==1)scanf("%d",&root);
        else if(type==2)
        {
            int u,v,x;scanf("%d%d%d",&u,&v,&x);
            /*
            if(u==root || v==root || ancestor(root,u)^ancestor(root,v)){update(1,n,1,in[1],out[1],x);continue;}
            int l=LCA(u,v);
            if(ancestor(root,u) && ancestor(root,v))update(1,n,1,in[l],out[l],x);
            else
            {
                int l1=LCA(u,root),l2=LCA(v,root);
                int w=l;
                if(dep[l1]>dep[w])w=l1;
                if(dep[l2]>dep[w])w=l2;
                if(!ancestor(w,root))update(1,n,1,in[w],out[w],x);
                else
                {
                    int ii=get(w,root);
                    update(1,n,1,in[1],out[1],x);
                    update(1,n,1,in[ii],out[ii],-x);
                }
            }
            */
            int w=LCA(u,v);
            if(!ancestor(w,root))update(1,n,1,in[w],out[w],x);
            else
            {
                u=LCA(u,root),v=LCA(v,root);
                if(dep[u]<dep[v])swap(u,v);
                update(1,n,1,in[1],out[1],x);
                if(u!=root)
                {
                    v=get(u,root);
                    update(1,n,1,in[v],out[v],-x);
                }
            }
        }
        else
        {
            int x;scanf("%d",&x);
            ll ans=0;
            if(x==root)ans=query(1,n,1,in[1],out[1]);
            else if(ancestor(x,root))
            {
                int ii=get(x,root);
                ans+=query(1,n,1,in[1],out[1]);
                ans-=query(1,n,1,in[ii],out[ii]);
            }
            else ans=query(1,n,1,in[x],out[x]);
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
/*
6 100
1 4 2 8 5 7
1 2
3 1
4 3
4 5
3 6
3 1
2 4 6 3
3 4
1 6
2 2 4 -5
1 4
3 3
*/
