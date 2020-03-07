#pragma G++ optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
const int mod=1e9+7;
char s[maxn];
int id(char c)
{
    if('a'<=c && c<='z')return c-'a';
    return c-'A'+26;
}
int num[55];
ll pw(ll a,int n)
{
    ll res=1;
    while(n)
    {
        if(n&1)res=res*a%mod;
        a=a*a%mod,n>>=1;
    }
    return res;
}
ll INV(ll a){return pw(a,mod-2);}
ll fac[maxn],inv[maxn];
void add(ll &a,ll b)
{
    a+=b;
    if(a>mod)a-=mod;
}
void sub(ll &a,ll b)
{
    a-=b;
    if(a<0)a+=mod;
}
void pre()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*i%mod;
    inv[maxn-1]=INV(fac[maxn-1]);
    for(int i=maxn-2;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
}
ll dp[maxn];
ll ans[55][55];
main()
{
    pre();
    scanf("%s",s);
    int n=strlen(s),k=52;
    for(int i=0;i<n;i++)num[id(s[i])]++;
    ll umr=fac[n/2]*fac[n/2]%mod;
    for(int i=0;i<k;i++)umr=umr*inv[num[i]]%mod;
    //printf("%lld\n",umr);
    dp[0]=1;
    for(int i=0;i<k;i++)
    {
        if(!num[i])continue ;
        for(int j=n;j>=num[i];j--)add(dp[j],dp[j-num[i]]);
    }
    for(int i=0;i<k;i++)ans[i][i]=dp[n/2];
    for(int i=0;i<k;i++)
    {
        if(!num[i])continue ;
        for(int j=num[i];j<=n;j++)sub(dp[j],dp[j-num[i]]);
        for(int j=i+1;j<k;j++)
        {
            if(!num[j])continue ;
            for(int l=num[j];l<=n;l++)sub(dp[l],dp[l-num[j]]);
            //printf("%d %d: ",i,j);
            //for(int i=1;i<=5;i++)printf("%lld ",dp[i]);puts("");
            ans[i][j]=ans[j][i]=2ll*dp[n/2]%mod;
            for(int l=n;l>=num[j];l--)add(dp[l],dp[l-num[j]]);
        }
        for(int j=n;j>=num[i];j--)add(dp[j],dp[j-num[i]]);

    }
    int q;scanf("%d",&q);
    //for(int i=0;i<5;i++){for(int j=0;j<5;j++)printf("%lld ",ans[i][j]);puts("");}
    while(q--)
    {
        int x,y;scanf("%d%d",&x,&y);x--,y--;
        x=id(s[x]),y=id(s[y]);
        printf("%lld\n",umr*ans[x][y]%mod);
    }
    return 0;
}
