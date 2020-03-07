#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define maxn 5050
ll c[maxn][maxn],fac[maxn];
void pre()
{
    for(int i=0;i<=5000;i++)c[i][0]=c[i][i]=1;
    for(int i=1;i<=5000;i++)
        for(int j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    //for(int i=0;i<=20;i++){for(int j=0;j<=i;j++)printf("%d ",c[i][j]);puts("");}
    fac[0]=1;
    for(int i=1;i<=5000;i++)fac[i]=(fac[i-1]*i)%mod;
}
ll sol(ll a,ll b)
{
    if(a>b)swap(a,b);
    ll ret=0;
    for(int i=0;i<=a;i++)ret=(ret+((c[a][i]*c[b][i])%mod)*fac[i])%mod;
    return ret;
}
ll get_ans(ll a,ll b,ll c){return (((a*b)%mod)*c)%mod;}
main()
{
    pre();
    ll a,b,c;scanf("%I64d%I64d%I64d",&a,&b,&c);
    ll ans=get_ans(sol(a,b),sol(b,c),sol(c,a));
    printf("%I64d\n",ans);
    return 0;
}
