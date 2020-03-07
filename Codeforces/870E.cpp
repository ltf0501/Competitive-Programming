#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define pii pair<int,int>
#define F first
#define S second
#define ALL(v) v.begin(),v.end()
#define ll long long
const int mod=1e9+7;
pii a[maxn];
int n;
vector<int> vx,vy;
vector<int> g[maxn<<1];
ll pw(ll a,int n)
{
    ll ret=1;
    while(n)
    {
        if(n&1)ret=ret*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ret;
}
int sz[maxn<<1];
pii p[maxn<<1];
int finds(int x){return p[x].F==x ? x : p[x].F=finds(p[x].F);}
void Union(int x,int y)
{
    int a=finds(x),b=finds(y);
    if(a==b)p[a].S=0;
    else
    {
        if(sz[a]>sz[b])swap(a,b);
        sz[b]+=sz[a];
        p[a].F=b;
        p[b].S&=p[a].S;
    }
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S);
        vx.push_back(a[i].F),vy.push_back(a[i].S);
    }
    sort(ALL(vx)),sort(ALL(vy));
    vx.resize(unique(ALL(vx))-vx.begin());
    vy.resize(unique(ALL(vy))-vy.begin());

    int u=vx.size(),v=vy.size();
    int tot=u+v;
    for(int i=1;i<=tot;i++)p[i]=pii(i,1),sz[i]=1;
    for(int i=1;i<=n;i++)
    {
        a[i].F=lower_bound(ALL(vx),a[i].F)-vx.begin()+1;
        a[i].S=lower_bound(ALL(vy),a[i].S)-vy.begin()+1;
        Union(a[i].F,a[i].S+u);
    }
    ll ans=1;
    for(int i=1;i<=tot;i++)if(p[i].F==i)
    {
        ll num=pw(2,sz[i]);
        if(p[i].S)num--;
        ans=ans*num%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
