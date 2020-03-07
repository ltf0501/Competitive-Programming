#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxm 105
const int mod=1e9+7;
ll n;
int m;
struct M
{
    ll t[maxm][maxm];
    M(){memset(t,0,sizeof(t));}
    M(int x)
    {
        for(int i=0;i<m;i++)t[i][i]=x;
    }
};
M operator * (const M& a,const M& b)
{
    M c;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)for(int k=0;k<m;k++)
        c.t[i][j]=(c.t[i][j]+a.t[i][k]*b.t[k][j]%mod)%mod;
    return c;
}
M pw(M a,ll n)
{
    M res(1);
    while(n)
    {
        if(n&1)res=res*a;
        n>>=1;a=a*a;
    }
    return res;
}
main()
{
    scanf("%lld%d",&n,&m);
    M ans;
    for(int i=0;i<m-1;i++)ans.t[i][i+1]=1;
    ans.t[m-1][0]=ans.t[m-1][m-1]=1;
    ans=pw(ans,n);
    printf("%lld\n",ans.t[m-1][m-1]);
    /*
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)printf("%lld ",ans.t[i][j]);puts("");
    }
    */
    return 0;
}
