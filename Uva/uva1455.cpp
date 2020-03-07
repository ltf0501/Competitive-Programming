#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxc 1000000+5
#define maxn 100000+5
struct Node
{
    int l,r,ns,nc;
    void sets(int l,int r,int ns,int nc)
    {
        this->l=l;
        this->r=r;
        this->ns=ns;
        this->nc=nc;
    }
}node[4*maxc];
int p[maxn],cnt[maxn],L[maxn],R[maxn];
int m;
void pushup(int o)
{
    node[o].sets(node[o*2].l,node[o*2+1].r,0,0);
}
void pushdown(int o)
{
    if(node[o].ns || node[o].nc)
    {
        node[o*2].ns+=node[o].ns;
        node[o*2].nc+=node[o].nc;
        node[o*2+1].ns+=node[o].ns;
        node[o*2+1].nc+=node[o].nc;
    }
}
void build(int o,int L,int R)
{
    if(L==R)
    {
        node[L].sets(L,R,0,0);
        return ;
    }
    int m=L+(R-L)/2;
    build(o*2,L,m);
    build(o*2+1,m+1,R);
    pushup(o);
}
void update(int o,int L,int R,int adds,int addc)
{
    if(L<=node[o].l && node[o].r<=R)
    {
        node[o].ns+=adds;
        node[o].nc+=addc;
        return ;
    }
    int m=node[o].l+(node[o].r-node[o].l)/2;
    pushdown(o);
    if(L<=m)update(o*2,L,R,adds,addc);
    if(R>m)update(o*2+1,L,R,adds,addc);
    pushup(o);
}
int findset(int x)
{
    return p[x]==x ? x : (p[x]=findset(p[x]));
}
void change(int o,int L,int R,int adds,int addc)
{
    if(R<L)return ;
    update(o,L,R,adds,addc);
}
void Union(int x,int y)
{
    x=findset(x);
    y=findset(y);
    if(x==y)return ;
    if(L[x]>=L[y])swap(x,y);
    if(R[x]<=L[y])
    {
        change(1,L[x],R[x]-1,0,cnt[y]);
        change(1,L[y],R[y]-1,0,cnt[x]);
        change(1,R[x],L[y]-1,1,cnt[x]+cnt[y]);
    }
    else if(R[x]<=R[y])
    {
        change(1,L[x],L[y]-1,0,cnt[y]);
        change(1,R[x],R[y]-1,0,cnt[x]);
        change(1,L[y],R[x]-1,-1,0);
    }
    else if(R[x]>=R[y])
    {
        change(1,L[x],L[y]-1,0,cnt[y]);
        change(1,R[y],R[x]-1,0,cnt[y]);
        change(1,L[y],R[y]-1,-1,0);
    }
    p[x]=y;
    cnt[y]+=cnt[x];
    L[y]=min(L[x],L[y]);
    R[y]=min(R[x],R[y]);
}
int query(int o,int x)
{
    if(node[o].l==x && node[o].r==x)return o;
    int ans;
    int m=node[o].l+(node[o].r-node[o].l)/2;
    pushdown(o);
    if(x<=m)ans=query(o*2,x);
    else ans=query(o*2+1,x);
    pushup(o);
    return ans;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        int k=0;
        for(int i=0;i<n;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            p[i]=i;cnt[i]=1;
            L[i]=R[i]=y;
            k=max(k,y);
        }
        scanf("%d",&m);
        build(1,0,maxc-5);
        char s[100];
        while(m--)
        {
            scanf("%s",s);
            if(s[0]=='r')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                Union(x,y);
            }
            if(s[0]=='l')
            {
                double q;scanf("%lf",&q);
                int u=query(1,(int)q);
                printf("%d %d\n",node[u].ns,node[u].nc);
            }

        }
    }
    return 0;
}

