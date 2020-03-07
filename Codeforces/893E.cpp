#include<bits/stdc++.h>
using namespace std;
#define maxn 1001000
#define ll long long
const int mod=1e9+7;
ll f[maxn],inv[maxn];
ll pw(ll a,int n)
{
    if(!n)return 1;
    if(n==1)return a;
    ll ret=pw(a,n>>1);
    ret=ret*ret%mod;
    if(n&1)ret=ret*a%mod;
    return ret;
}
ll INV(ll a){return pw(a,mod-2);}
void pre()
{
    f[0]=1;
    for(int i=1;i<=maxn-10;i++)f[i]=f[i-1]*i%mod;
    for(int i=0;i<=maxn-10;i++)inv[i]=INV(f[i]);
}
vector<int> v;
void gao(int n)
{
    int tmp=n;
    for(int i=2;i*i<=n;i++)if(tmp%i==0)
    {
        int cnt=0;
        while(tmp%i==0)tmp/=i,cnt++;
        v.push_back(cnt);
    }
    if(tmp!=1)v.push_back(1);
}
ll C(int a,int b)
{
    return f[a]*inv[b]%mod*inv[a-b]%mod;
}
main()
{
    pre();
    int q;scanf("%d",&q);
    while(q--)
    {
        int n,k;scanf("%d%d",&n,&k);
        v.clear();
        gao(n);
        ll ans=1;
        for(int s : v)ans=ans*C(k+s-1,s)%mod;
        ans=ans*pw(2,k-1)%mod;
        printf("%I64d\n",ans);
    }
    return 0;
}
