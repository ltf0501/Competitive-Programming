#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define pii pair<int,int>
#define F first
#define S second
int n;
int a[maxn],pos[maxn],ans[maxn];
int topo[maxn],dfs_clock;
bool vis[maxn];
pii seg[maxn<<2];
void push_up(int o){seg[o]=max(seg[o<<1],seg[o<<1|1]);}
void build(int l,int r,int o)
{
    if(l==r){seg[o]=pii(pos[l],l);return ;}
    int m=(l+r)>>1;
    build(l,m,o<<1),build(m+1,r,o<<1|1);
    push_up(o);
}
void update(int l,int r,int o,int p,int x)
{
    if(l==r){seg[o]=pii(x,p);return ;}
    int m=(l+r)>>1;
    if(p<=m)update(l,m,o<<1,p,x);
    else update(m+1,r,o<<1|1,p,x);
    push_up(o);
}
pii query(int l,int r,int o,int ql,int qr)
{
    if(ql<=l && r<=qr)return seg[o];
    int m=(l+r)>>1;
    if(qr<=m)return query(l,m,o<<1,ql,qr);
    if(ql>m)return query(m+1,r,o<<1|1,ql,qr);
    return max(query(l,m,o<<1,ql,qr),query(m+1,r,o<<1|1,ql,qr));
}
void dfs(int u)
{
    if(u<=0 || u>n || !a[u])return ;
    //printf("now = %d\n",u);
    a[u]=0;
    update(1,n,1,u,0);
    dfs(pos[u]);
    while(1)
    {
        pii nxt=query(1,n,1,1,pos[u]);
        //printf("%d %d %d\n",nxt.F,nxt.S,u);
        if(nxt.F>u && nxt.S && !vis[nxt.S])dfs(nxt.S);
    }
    topo[dfs_clock++]=u;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==-1)a[i]=n+1;
        else pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++)if(!pos[i])pos[i]=n+1;
    for(int i=1;i<=n;i++)printf("%d ",pos[i]);puts("");
    build(1,n,1);
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
    for(int i=0;i<n;i++)ans[topo[i]]=n-i;
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}
