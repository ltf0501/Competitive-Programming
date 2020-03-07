#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int dp[9][9],tmp[9][9];
int cnt[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        cnt[x]++;
        if(cnt[x]>=9)cnt[x]-=3,ans++;
    }
    for(int i=0;i<=8;i++)
        for(int j=0;j<=8;j++)tmp[i][j]=-1;
    tmp[cnt[1]][cnt[2]]=0;
    int umr=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<=8;j++)
            for(int k=0;k<=8;k++)dp[j][k]=-1;
        for(int j=0;j<=8;j++)for(int k=0;k<=8;k++)
        {
            if(tmp[j][k]==-1)continue ;
            for(int x=0;x<=min({j,k,cnt[i+2]});x++)
            {
                dp[k-x][cnt[i+2]-x]=max(dp[k-x][cnt[i+2]-x],tmp[j][k]+x+(j-x)/3);
                umr=max(umr,dp[k-x][cnt[i+2]-x]);
            }
        }
        for(int j=0;j<=8;j++)
            for(int k=0;k<=8;k++)tmp[j][k]=dp[j][k];
    }
    printf("%d\n",ans+umr);
    return 0;
}
