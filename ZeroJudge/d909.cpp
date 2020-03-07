#include<bits/stdc++.h>
using namespace std;
#define maxm 500010
#define maxn 10010
#define ll long long
int p[maxn],sz[maxn];
struct edge
{
    int u,v;
    ll d;
    bool operator < (const edge& b)const
    {
        return d<b.d;
    }
}e[maxm];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
bool Union(int x,int y)
{
    int a=finds(x),b=finds(y);
    if(a==b)return 0;
    if(sz[a]>sz[b])swap(a,b);
    p[a]=b,sz[b]+=sz[a];
    return 1;
}
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;ll d;scanf("%d%d%lld",&u,&v,&d);
        u++,v++;
        e[i]={u,v,d};
    }
    sort(e+1,e+m+1);
    //for(int i=1;i<=m;i++)printf("%d %d %lld\n",e[i].u,e[i].v,e[i].d);
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    ll ans=0;
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        if(Union(e[i].u,e[i].v))ans+=e[i].d,cnt++;
        if(cnt==n-1)break;
    }
    printf("%lld\n",ans);
    return 0;
}
