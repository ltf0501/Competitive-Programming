#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
const int mod=1e9+7;
int n,q;
char c[maxn];
int pre[maxn];
ll pw(ll a,int n)
{
    ll ret=1;
    while(n)
    {
        if(n&1)ret=ret*a%mod;
        a=a*a%mod,n>>=1;
    }
    return ret;
}
main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",c+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+(c[i]-'0');
    while(q--)
    {
        int l,r;scanf("%d%d",&l,&r);
        int a=pre[r]-pre[l-1];
        int b=(r-l+1)-a;
        ll c=(pw(2,a)+mod-1)%mod;
        ll ans=c*pw(2,b)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
