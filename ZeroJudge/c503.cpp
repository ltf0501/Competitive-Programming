#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
struct E
{
    int u,v,d;
    bool operator < (const E& rhs)const{return d<rhs.d;}
};
vector<E> edge;
int p[maxn],sz[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
bool Union(int x,int y)
{
    int a=finds(x),b=finds(y);
    if(a==b)return 0;
    if(sz[a]<sz[b])swap(a,b);
    sz[a]+=sz[b],p[b]=a;
    return 1;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n*(n-1)/2;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        edge.push_back({x,y,d});
    }
    sort(edge.begin(),edge.end());
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    int cnt=0,ans=0;
    for(E e : edge)
    {
        int x=e.u,y=e.v,d=e.d;
        if(Union(x,y))cnt++,ans+=e.d;
        if(cnt==n-1)break;
    }
    printf("%d\n",ans);
    return 0;
}
