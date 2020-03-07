#include<bits/stdc++.h>
using namespace std;
#define maxn 155
#define mod 1000000009
#define ll long long
typedef vector<vector<ll> > Matrix;
int n,m,q,l;
inline Matrix operator * (const Matrix& a,const Matrix& b)
{
    Matrix c(n,vector<ll>(n,0));
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)
        c[i][j]=(c[i][j]+a[i][k]*b[k][j])%mod;
    return c;
}
Matrix pow(Matrix a,int n)
{
    if(n==1)return a;
    Matrix ans=pow(a,n/2);
    ans=ans*ans;
    if(n&1)ans=ans*a;
    return ans;
}
main()
{
    scanf("%d%d%d%d",&n,&m,&q,&l);
    Matrix c(n,vector<ll>(n,0));
    while(m--)
    {
        int x,y;scanf("%d%d",&x,&y);
        c[x][y]++;
    }
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)printf("%lld ",c[i][j]);
        puts("");
    }
    */
    Matrix ans=pow(c,l);
    while(q--)
    {
        int x,y;scanf("%d%d",&x,&y);
        printf("%lld\n",ans[x][y]);
    }
    return 0;
}
