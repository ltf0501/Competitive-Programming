#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,m,k;
struct E
{
    int u,v,w;
    bool operator < (const E& rhs)const{return w<rhs.w;}
};
vector<E> edge;
int p[maxn],sz[maxn],sz2[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
int flag;
bool Union(int x,int y)
{
    int a=finds(x),b=finds(y);
    if(a==b)return 0;
    if(sz[a]<sz[b])swap(a,b);
    p[b]=a,sz[a]+=sz[b],sz2[a]+=sz2[b];
    return sz2[a]==k;
}
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        int x;scanf("%d",&x);
        sz2[x]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        if(x==y)continue;
        edge.push_back({x,y,d});
    }
    sort(edge.begin(),edge.end());
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(auto e : edge)
    {
        int x=e.u,y=e.v,d=e.w;
        if(Union(x,y))
        {
            for(int i=1;i<=k;i++)printf("%d ",d);
            return 0;
        }
    }
    return 0;
}
