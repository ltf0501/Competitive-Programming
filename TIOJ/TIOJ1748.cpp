#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
const int mod=1e9;
int n,m,k;
int p[maxn*8],sz[maxn*8];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void Union(int a,int b)
{
    int x=finds(a),y=finds(b);
    if(x==y)return ;
    if(sz[x]<sz[y])swap(x,y);
    sz[x]+=sz[y],p[y]=x;
}
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
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<2*(n+m);i++)p[i]=i,sz[i]=1;
    for(int i=1;i<=k;i++)
    {
        int x,y,c;scanf("%d%d%d",&x,&y,&c);
        x--,y--;
        c^=((x&1) && (y&1));
        y+=n;
        if(c)Union(x,y),Union(x+n+m,y+n+m);
        else Union(x,y+n+m),Union(x+n+m,y);
    }
    int cnt=0;
    for(int i=0;i<n+m;i++)
    {
        if(finds(i)==finds(i+n+m))return 0*puts("0");
        if(p[i]==i)cnt++;
    }
    printf("%lld\n",pw(2,cnt-1));
    return 0;
}
