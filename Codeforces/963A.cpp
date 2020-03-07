#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
const int mod=1e9+9;
int n,k;
ll a,b;
char s[maxn];
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
ll inv(ll a){return pw(a,mod-2);}
int t(char c)
{
    if(c=='+')return 1;
    return -1;
}
main()
{
    scanf("%d%lld%lld%d",&n,&a,&b,&k);
    scanf("%s",s);
    ll r=b*inv(a)%mod;
    ll p=0,cur=pw(a,n);
    for(int i=0;i<k;i++)
    {
        p=(p+t(s[i])*cur%mod+mod)%mod;
        cur=cur*r%mod;
        if(p<0)p+=mod;
    }
    ll s;
    int d=(n+1)/k;
    r=pw(r,k);
    if(r!=1)s=(pw(r,d)-1)*inv(r-1)%mod;
    else s=d;
    //printf("%lld %lld\n",p,s);
    printf("%lld\n",p*s%mod);
    return 0;
}
