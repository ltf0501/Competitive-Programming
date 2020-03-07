#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1010
#define maxw 10010
const ll INF=1e16;
int n,w,b,x;
int a[maxn];
ll cost[maxn];
ll dp[maxn][maxw];
main()
{
    scanf("%d%d%d%d",&n,&w,&b,&x);
    //for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    //for(int i=1;i<=n;i++)scanf("%lld",&cost[i]);
    a[1]=10000;
    for(int i=1;i<=n;i++)cost[i]=1;
    for(int i=0;i<=n;i++)for(int j=0;j<maxw;j++)dp[i][j]=-INF;
    dp[0][0]=w;
    int tot=0,ans=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        tot+=a[i];
        for(int j=0;j<=tot;j++)///dp(i,j)=max(min(dp(i-1,j-k)+x,w+(j-k)b)-cost[i]*k))
        {
            //ll cap=w+1ll*j*b;
            for(int k=0;k<=min(j,a[i]);k++)
            {cnt++;
                if(dp[i-1][j-k]==-INF)continue;
                ll tmp=min(dp[i-1][j-k]+x,w+1ll*(j-k)*b)-cost[i]*k;
                if(tmp<0)continue;
                dp[i][j]=max(dp[i][j],tmp);
                //cap+=b;
                ans=max(ans,j);
            }
        }
    }
    printf("%d\n",cnt);
    printf("%d\n",ans);
    return 0;
}
