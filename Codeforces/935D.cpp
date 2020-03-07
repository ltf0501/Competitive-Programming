#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
const int mod=1e9+7;
int a[maxn],b[maxn],n,m;
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
ll inv(ll x){return pw(x,mod-2);}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&b[i]);
    ll ans=0,cur=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {
            if(b[i]==0)
            {
                ll t=cur*(m-1)%mod*inv(2*m)%mod;
                ans+=t;
                cur=cur*inv(m)%mod;
            }
            else
            {
                ll t=cur*(m-b[i])%mod*inv(m)%mod;
                ans+=t;
                cur=cur*inv(m)%mod;
            }
        }
        else
        {
            if(b[i]==0)
            {
                ll t=cur*(a[i]-1)%mod*inv(m)%mod;
                ans+=t;
                cur=cur*inv(m)%mod;
            }
            else
            {
                if(a[i]==b[i])continue;
                if(a[i]>b[i])ans+=cur;
                break;
            }
        }
    }
    printf("%lld\n",ans%mod);
    return 0;
}
