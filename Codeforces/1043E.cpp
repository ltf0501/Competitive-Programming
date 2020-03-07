#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300010
struct P
{
    int x,y,id;
    bool operator < (const P& rhs){return x-y<rhs.x-rhs.y;}
};
int n,m;
P a[maxn];
ll pre[maxn],suf[maxn],ans[maxn];
int pos[maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].id=i;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pos[a[i].id]=i;
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i].x;
    for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i].y;
    for(int i=1;i<=n;i++)
    {
        int id=a[i].id;
        ans[id]=pre[i-1]+suf[i+1]+1ll*(i-1)*a[i].y+1ll*(n-i)*a[i].x;
    }
    //for(int i=1;i<=n;i++)printf("%lld ",ans[i]);puts("");
    //for(int i=1;i<=n;i++)printf("%d %d %d\n",a[i].x,a[i].y,a[i].id);
    //for(int i=1;i<=n;i++)printf("%d ",pos[i]);puts("");
    for(int i=1;i<=m;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        int p=pos[u],q=pos[v];
        ll tmp=min(a[p].x+a[q].y,a[p].y+a[q].x);
        ans[u]-=tmp,ans[v]-=tmp;
    }
    for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
    return 0;
}
