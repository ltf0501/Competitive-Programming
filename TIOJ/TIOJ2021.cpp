#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
typedef vector<vector<ll> > Matrix;
inline Matrix operator * (const Matrix& a,const Matrix& b)
{
    Matrix c(2,vector<ll>(2,0));
    for(int i=0;i<2;i++)for(int j=0;j<2;j++)
        for(int k=0;k<2;k++)c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
        return c;
}
Matrix power(Matrix a,ll n)
{
    Matrix p(2,vector<ll>(2,0));
    p[0][0]=p[1][1]=1;
    if(!n)return p;
    if(n==1)return a;
    Matrix ret=power(a,n>>1);
    ret=ret*ret;
    if(n&1)ret=ret*a;
    return ret;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int l,r;scanf("%d%d",&l,&r);
        Matrix p(2,vector<ll>(2,0));
        p[0][0]=p[1][0]=p[0][1]=1;p[1][1]=0;
        Matrix tmp=power(p,r-1);
        ll y=(tmp[1][0]+tmp[1][1])%mod;
        ll x;
        if(l==1)x=0;
        else
        {
            tmp=power(p,l-2);
            x=(tmp[1][0]+tmp[1][1])%mod;
        }
        printf("%lld %lld\n",y,x);
        ll ans=((y*(y-1)/2)-(x*(x-1)/2))%mod;
        if(ans<0)ans+=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
