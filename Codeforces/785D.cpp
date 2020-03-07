#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200000+5
const int mod=1e9+7;
char c[maxn];
int a[maxn],b[maxn];
ll f[maxn],k[maxn];
ll pow(ll x,int y)
{
    if(y==1)return x;
    ll ans=pow(x,y/2);
    ans=(ans*ans)%mod;
    if(y&1)ans=(ans*x)%mod;
    return ans;
}
main()
{
    scanf("%s",c);
    int n=strlen(c);
    int now=0;
    for(int i=0;i<n;i++)
    {
        a[i]=now;
        if(c[i]=='(')now++;
    }
    now=0;
    for(int i=n-1;i>=0;i--)
    {
        b[i]=now;
        if(c[i]==')')now++;
    }
    f[0]=k[0]=1;
    for(int i=1;i<=n;i++)f[i]=(f[i-1]*i)%mod,k[i]=pow(f[i],mod-2);
    ll ans=0;
    for(int i=0;i<n;i++)if(c[i]=='(')
    {
        ll x=1;
        x=(x*f[a[i]+b[i]])%mod;
        x=(x*k[a[i]+1])%mod;
        x=(x*k[b[i]-1])%mod;
        ans=(ans+x)%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}
