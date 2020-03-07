#include<cstdio>
#include<vector>
using namespace std;
#define maxn 100010
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))
vector<pii> g[maxn],ch[maxn];
vector<int> now;
int n,q;
ll dis[20][maxn];
bool vis[maxn];
int sz[maxn],mx[maxn];
struct Cen
{
    int fa,sz,dep;
    ll val,no;
}cen[maxn];
void get_cen(int u)
{
    vis[u]=1;
    sz[u]=1,mx[u]=0;
    now.push_back(u);
    for(pii v : g[u])if(!vis[v.F])
    {
        get_cen(v.F);
        sz[u]+=sz[v.F];
        mx[u]=max(mx[u],sz[v.F]);
    }
}
void get_dis(int u,int dep,ll d)
{
    vis[u]=1;dis[dep][u]=d;
    for(pii v : g[u])if(!vis[v.F])
        get_dis(v.F,dep,d+v.S);
}
int dfs(int u,int dep,int fa)
{
    get_cen(u);
    int s=now.size();
    int rt=-1;
    for(int w : now)
    {
        if(max(s-sz[w],mx[w])<=s/2)rt=w;
        vis[w]=0;
    }
    get_dis(rt,dep,0);
    for(int w : now)vis[w]=0;
    now.clear();
    vis[rt]=1;
    cen[rt]={fa,0,dep,0,0};
    for(pii v : g[rt])if(!vis[v.F])
        ch[rt].push_back(pii(dfs(v.F,dep+1,rt),v.F));
    return rt;
}
void update(int x,int c)
{
    int p=x;
    while(p!=-1)
    {
        //printf("p=%d\n",p);
        cen[p].val+=dis[cen[p].dep][x]*c;
        cen[p].no+=dis[cen[p].dep-1][x]*c;
        cen[p].sz+=c;
        p=cen[p].fa;
    }
}
ll cal(int x)
{
    int p=x;
    ll ret=0;
    int Sz=0;
    while(p!=-1)
    {
        ret+=cen[p].val-cen[p].no;
        ret+=(cen[p].sz-Sz)*dis[cen[p].dep][x];
        Sz=cen[p].sz;
        p=cen[p].fa;
        //printf("d=%lld\n",dis[cen[p].dep][x]);
        //printf("ret=%lld\n",ret);
    }
    return ret;
}
ll query(int root)
{
    ll ret=cal(root);
    for(pii v : ch[root])
    {
        ll tmp=cal(v.S);
        if(tmp<ret)return query(v.F);
    }
    return ret;
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        g[x].push_back(pii(y,d)),g[y].push_back(pii(x,d));
    }
    int root=dfs(1,1,-1);
    //printf("%d\n",root);
    //for(int i=1;i<=n;i++)printf("%d: %d %d\n",i,cen[i].fa,cen[i].dep);
    while(q--)
    {
        int x,c;scanf("%d%d",&x,&c);
        update(x,c);
        //int k=find_mi(root);
        //printf("k=%d\n",k);
        printf("%lld\n",query(root));
    }
    return 0;
}
