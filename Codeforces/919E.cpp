#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a,b,p;ll x;
ll pw(ll a,int n)
{
    ll ret=1;
    while(n)
    {
        if(n&1)ret=ret*a%p;
        a=a*a%p;
        n>>=1;
    }
    return ret;
}
main()
{
    scanf("%d%d%d%I64d",&a,&b,&p,&x);
    int cur;
    ll ans=0;
    for(int i=0;i<p-1;i++)
    {
        ll t=b*pw(a,p-1-i)%p;
        ll s=(1ll*p*(i-t+p-1)+t)%(1ll*p*(p-1));
        //printf("%I64d\n",s);
        if(s<=x)
        {
            ans+=(x-s)/(1ll*p*(p-1))+1;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
