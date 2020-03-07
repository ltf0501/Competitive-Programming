#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn];
int n,q;
vector<int> g[maxn],now;
bool vis[maxn];
int dis[20][maxn];
int sz[maxn],mx[maxn];
struct Cen
{
    int fa,dep;
}cen[maxn];
struct BIT
{
    vector<int> bit;
    int n;
    void init(int sz){bit.resize(sz+2);n=sz+1;}
    void add(int x,int d)
    {
        for(int i=x;i<=n && i;i+=i&-i)bit[i]+=d;
    }
    int query(int x)
    {
        int ret=0;
        x=min(x,n);//­«­n
        for(int i=x;i>0;i-=i&-i)ret+=bit[i];
        return ret;
    }
}f1[maxn],f2[maxn];
void get_cen(int u)
{
    vis[u]=1;
    sz[u]=1,mx[u]=0;
    now.push_back(u);
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(vis[v])continue;
        get_cen(v);
        sz[u]+=sz[v];
        mx[u]=max(mx[u],sz[v]);
    }
}
void get_dis(int u,int dep,int d)
{
    vis[u]=1;dis[dep][u]=d;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(!vis[v])get_dis(v,dep,d+1);
    }
}
void dfs(int u,int dep,int fa)
{
    get_cen(u);
    int rt=-1;
    int s=now.size();
    for(int i=0;i<now.size();i++)
    {
        int w=now[i];
        if(max(mx[w],s-sz[w])<=s/2)rt=w;
        vis[w]=0;
    }
    get_dis(rt,dep,0);
    for(int i=0;i<now.size();i++)vis[now[i]]=0;
    //printf("%d: ",u);for(int w : now)printf("%d ",w);puts("");
    //printf("rt=%d\n",rt);
    f1[rt].init(s+1),f2[rt].init(s+1);
    now.clear();
    vis[rt]=1;
    cen[rt]={fa,dep};
    for(int i=0;i<g[rt].size();i++)
    {
        int v=g[rt][i];
        if(!vis[v])dfs(v,dep+1,rt);
    }
}
void update(int x,int v)
{
    int p=x;
    while(p!=-1)
    {
        //printf("f1 %d: %d %d\n",p,dis[cen[p].dep][x]+1,v);
        //printf("f2 %d: %d %d\n",p,dis[cen[p].dep-1][x]+1,v);
        f1[p].add(dis[cen[p].dep][x]+1,v);
        f2[p].add(dis[cen[p].dep-1][x]+1,v);
        p=cen[p].fa;
    }
}
int query(int x,int k)
{
    int ret=0;
    int p=x;
    while(p!=-1)
    {
        int d1=dis[cen[p].dep][x];
        int d2=dis[cen[p].dep-1][x];
        ret+=f1[p].query(k-d1+1)-f2[p].query(k-d2+1);
        //printf("%d %d %d %d %d\n",p,k-d1+1,k-d2+1,f1[p].query(k-d1+1),f2[p].query(k-d2+1));
        p=cen[p].fa;
    }
    return ret;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    memset(dis,-1,sizeof(dis));
    dfs(1,1,-1);
    //for(int i=1;i<=n;i++)printf("%d: %d\n",i,f1[i].n);puts("");
    //for(int i=1;i<=n;i++)printf("%d: %d %d\n",i,cen[i].fa,cen[i].dep);
    for(int i=1;i<=n;i++)update(i,a[i]);
    int ans=0;
    while(q--)
    {
        int type,x,k;scanf("%d%d%d",&type,&x,&k);
        x^=ans,k^=ans;
        if(type==1)update(x,k-a[x]),a[x]=k;
        else printf("%d\n",ans=query(x,k));
    }
    return 0;
}
