#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
#define ll long long
const ll INF=1e14;
ll a[maxn],dp[maxn][maxn],ans=0;
int n;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n+1;i++)for(int j=i;j<=n+1;j++)dp[i][j]=1e14;
        for(int i=1;i<=n;i++)
        {
            ll x,y;scanf("%lld%lld",&x,&y);
            a[i]=x;
            if(i==n)a[n+1]=y;
        }
        //for(int i=1;i<=n+1;i++)printf("%lld ",a[i]);puts("");
        for(int i=1;i<=n;i++)dp[i][i]=0;
        //for(int i=1;i<=n;i++)dp[i][i+1]=a[i]*a[i+1]*a[i+2];
        for(int l=1;l<n;l++)
        {
            for(int i=1;i+l<=n;i++)
                for(int k=i;k<i+l;k++)dp[i][i+l]=min(dp[i][i+l],dp[i][k]+dp[k+1][i+l]+a[i]*a[i+l+1]*a[k+1]);
        }
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)printf("%lld ",dp[i][j]);puts("");
        }
        */
        printf("%lld\n",(dp[1][n]+999)/1000);
        ans+=dp[1][n];
    }
    printf("%lld\n",(ans+999)/1000);
    return 0;
}
