#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int fa[maxn],sz[maxn],dep[maxn],top[maxn],maxson[maxn];
int in[maxn];
int num;
int val[maxn];
struct node
{
    int u,v,dis;
}e[maxn<<2];
vector<int> g[maxn];
void dfs1(int u,int f,int d)
{
    sz[u]=1;
    maxson[u]=0;
    fa[u]=f;
    dep[u]=d;
    int tmp=0;
    for(int v : g[u])
    {
        if(v==f)continue;
        dfs1(v,u,d+1);
        sz[u]+=sz[v];
        if(sz[v]>tmp)maxson[u]=v,tmp=sz[v];
    }
}
void dfs2(int u,int tp)
{
    top[u]=tp;in[u]=++num;
    if(maxson[u])dfs2(maxson[u],tp);
    for(int v : g[u])
    {
        if(v==maxson[u] || v==fa[u])continue;
        dfs2(v,v);
    }
}
int mx[maxn<<2];
void push_up(int id)
{
    mx[id]=max(mx[id<<1],mx[id<<1|1]);
}
void build(int l,int r,int id)
{
    if(l==r)
    {
        mx[id]=val[l];
        return ;
    }
    int m=(l+r)>>1;
    build(l,m,id<<1),build(m+1,r,id<<1|1);
    push_up(id);
}
void update(int l,int r,int id,int p,int x)
{
    if(l==r)
    {
        mx[id]=x;
        return ;
    }
    int m=(l+r)>>1;
    if(p<=m)update(l,m,id<<1,p,x);
    else update(m+1,r,id<<1|1,p,x);
    push_up(id);
}
int find_max(int l,int r,int id,int ql,int qr)
{
    if(ql<=l && r<=qr)return mx[id];
    int m=(l+r)>>1;
    int ans=0;
    if(ql<=m)ans=find_max(l,m,id<<1,ql,qr);
    if(qr>m)ans=max(ans,find_max(m+1,r,id<<1|1,ql,qr));
    return ans;
}
int query(int u,int v)
{
    int tp1=top[u],tp2=top[v];
    int ans=-1;
    while(tp1!=tp2)
    {
        if(dep[tp1]<dep[tp2])swap(tp1,tp2),swap(u,v);
        ans=max(ans,find_max(1,num,1,in[tp1],in[u]));
        u=fa[tp1];
        tp1=top[u];
        //printf("now = %d\n",ans);
    }
    if(u==v)return ans;
    if(dep[u]>dep[v])swap(u,v);
    ans=max(ans,find_max(1,num,1,in[maxson[u]],in[v]));
    return ans;
}
void init(int n)
{
    for(int i=1;i<=n;i++)g[i].clear();
    num=0;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        init(n);
        for(int i=1;i<n;i++)
        {
            int x,y,d;scanf("%d%d%d",&x,&y,&d);
            e[i]=(node){x,y,d};
            g[x].push_back(y),g[y].push_back(x);
        }
        dfs1(1,0,1);
        dfs2(1,1);
        for(int i=1;i<n;i++)
        {
            if(dep[e[i].u]<dep[e[i].v])swap(e[i].u,e[i].v);//:讓u是v的孩子
            val[in[e[i].u]]=e[i].dis;
        }
        //for(int i=1;i<=n;i++)printf("%d ",val[i]);puts("");
        build(1,num,1);
        //for(int i=1;i<=100;i++)printf("%d ",mx[i]);
        char s[10];
        while(~scanf("%s",s) && s[0]!='D')
        {
            int x,y;scanf("%d%d",&x,&y);
            if(s[0]=='C')
            {
                update(1,num,1,in[e[x].u],y);
            }
            else
            {
                printf("%d\n",query(x,y));
            }
        }
    }
    return 0;
}
/*
1
14
1 2 9
1 3 7
1 4 1
2 5 13
2 6 10
3 7 8
4 8 6
4 9 2
4 10 5
6 11 11
6 12 12
9 13 3
13 14 4
*/
