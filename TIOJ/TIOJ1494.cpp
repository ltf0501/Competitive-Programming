#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
#define mod 1000000007
typedef vector<vector<ll> > Matrix;
inline Matrix operator * (const Matrix &a,const Matrix &b)
{
    Matrix c(2,vector<ll>(2,0));
    for(int k=0;k<=1;k++)
        for(int i=0;i<=1;i++)
            for(int j=0;j<=1;j++)c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
    return c;
}
Matrix pwr(Matrix a,ll n)
{
    if(n==1)return a;
    Matrix x=pwr(a,n>>1);
    x=x*x;
    if(n&1)x=x*a;
    return x;
}
ll gcd(ll a,ll b)
{
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}
main()
{
    ll x,y;
    scanf("%lld%lld",&x,&y);
    ll k=gcd(x+1,y+1)-1;
    //printf("%lld\n",k);
    if(k<=1)puts("1");
    else
    {
        Matrix x(2,vector<ll>(2,0));
        x[0][0]=x[0][1]=x[1][0]=1,x[1][1]=0;
        Matrix a=pwr(x,k-1);
        //printf("%lld %lld\n%lld %lld\n",a[0][0],a[0][1],a[1][0],a[1][1]);
        printf("%lld\n",(a[0][0]+a[0][1])%mod);
    }
    return 0;
}
