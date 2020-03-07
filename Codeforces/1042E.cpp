#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
#define ll long long
const int mod=998244353;
struct P
{
    int x,y,d;
    bool operator < (const P& rhs){return d<rhs.d;}
};
ll pw(ll a,int n)
{
    ll ret=1;
    while(n)
    {
        if(n&1)ret=ret*a%mod;
        n>>=1;
        a=a*a%mod;
    }
    return ret;
}
ll inv(ll a){return pw(a,mod-2);}
vector<P> v;
int n,m;
ll x1[maxn*maxn],y1[maxn*maxn],x2[maxn*maxn],y2[maxn*maxn];
ll dp[maxn][maxn],sum[maxn*maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        int d;scanf("%d",&d);
        v.push_back({i,j,d});
    }
    sort(v.begin(),v.end());
    x1[0]=v[0].x,y1[0]=v[0].y,x2[0]=v[0].x*v[0].x,y2[0]=v[0].y*v[0].y;
    for(int i=1;i<v.size();i++)
    {
        x1[i]=(x1[i-1]+v[i].x)%mod;
        y1[i]=(y1[i-1]+v[i].y)%mod;
        x2[i]=(x2[i-1]+v[i].x*v[i].x)%mod;
        y2[i]=(y2[i-1]+v[i].y*v[i].y)%mod;
    }
    int pre=-1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].d>v[i-1].d)pre=i-1;
        ll tmp=(sum[pre]+x2[pre]+y2[pre]-2ll*v[i].x*x1[pre]%mod-2ll*v[i].y*y1[pre]%mod)%mod;
        if(tmp<0)tmp+=mod;
        if(~pre)dp[v[i].x][v[i].y]=((1ll*inv(pre+1)*tmp)%mod+v[i].x*v[i].x+v[i].y*v[i].y)%mod;
        sum[i]=(sum[i-1]+dp[v[i].x][v[i].y])%mod;
    }
    int x,y;scanf("%d%d",&x,&y);
    printf("%lld\n",dp[x][y]);
    return 0;
}
