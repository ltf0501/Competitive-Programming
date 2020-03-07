#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define maxk 201
#define ll long long
const int mod=998244353;
ll dp[maxn][maxk][2],sum[maxn],sum2[maxn];
int n;
int a[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(a[1]!=-1)dp[1][a[1]][0]=1;
    else{for(int i=1;i<maxk;i++)dp[1][i][0]=1;}
    for(int k=1;k<maxk;k++)sum[k]=(sum[k-1]+dp[1][k][0]+dp[1][k][1])%mod;
    for(int k=1;k<maxk;k++)sum2[k]=(sum2[k-1]+dp[1][k][1])%mod;
    for(int i=2;i<=n;i++)
    {
        if(a[i]==-1)
        {
            if(a[i-1]==-1)
            {
                for(int j=1;j<maxk;j++)
                {
                    dp[i][j][0]=sum[j-1];
                    dp[i][j][1]=(dp[i-1][j][0]+sum2[maxk-1]-sum2[j-1])%mod;
                    if(dp[i][j][1]<0)dp[i][j][1]+=mod;
                }
            }
            else
            {
                for(int j=1;j<maxk;j++)
                {
                    if(j>a[i-1])dp[i][j][0]=(dp[i-1][a[i-1]][0]+dp[i-1][a[i-1]][1])%mod;
                    else dp[i][j][1]=((a[i-1]==j ? dp[i-1][a[i-1]][0] : 0)+dp[i-1][a[i-1]][1])%mod;
                }
            }
        }
        else
        {
            if(a[i-1]==-1)
            {
                for(int k=1;k<maxk;k++)
                {
                    if(a[i]>k)dp[i][a[i]][0]=(dp[i][a[i]][0]+dp[i-1][k][0]+dp[i-1][k][1])%mod;
                    else dp[i][a[i]][1]=(dp[i][a[i]][1]+(k==a[i] ? dp[i-1][k][0] : 0)+dp[i-1][k][1])%mod;
                }
            }
            else
            {
                if(a[i]>a[i-1])dp[i][a[i]][0]=dp[i-1][a[i-1]][0]+dp[i-1][a[i-1]][1];
                else dp[i][a[i]][1]=(a[i]==a[i-1] ? dp[i-1][a[i-1]][0] : 0)+dp[i-1][a[i-1]][1];
                //dp[i][a[i]][(a[i]<=a[i-1])]=(a[i]==a[i-1] ? dp[i-1][a[i-1]][0] : 0)+dp[i-1][a[i-1]][1];
            }
        }
        for(int k=1;k<maxk;k++)sum[k]=(sum[k-1]+dp[i][k][0]+dp[i][k][1])%mod;
        for(int k=1;k<maxk;k++)sum2[k]=(sum2[k-1]+dp[i][k][1])%mod;
        //for(int j=1;j<=20;j++)printf("%lld ",dp[i][j][0]);puts("");
        //for(int j=1;j<=20;j++)printf("%lld ",dp[i][j][1]);puts("");puts("");
    }
    ll ans=0;
    if(a[n]==-1)
    {
        for(int i=1;i<maxk;i++)ans=(ans+dp[n][i][1])%mod;
    }
    else ans=dp[n][a[n]][1];
    printf("%lld\n",ans);
    return 0;
}

