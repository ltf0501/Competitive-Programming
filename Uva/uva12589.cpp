#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
struct vec
{
    int x,y;
}v[55];
bool cmp(vec a,vec b)
{
    return b.x*a.y>b.y*a.x;//a斜率是否大於b
}
main()
{
    int t,cas=0;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int sumh=0;
        for(int i=0;i<n;i++){scanf("%d%d",&v[i].x,&v[i].y);sumh+=v[i].y;}
        sort(v,v+n,cmp);
        int dp[m+1][sumh+1],dph[m+1];
        memset(dp,0,sizeof(dp));memset(dph,0,sizeof(dph));
        dp[0][0]=1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=min(m-1,i);j>=0;j--)
            {
                for(int k=min(dph[j],sumh-v[i].y);k>=0;k--)
                {
                    if(dp[j][k])dp[j+1][k+v[i].y]=max(dp[j+1][k+v[i].y],dp[j][k]+(2*k+v[i].y)*v[i].x);
                    dph[j+1]=max(dph[j+1],k+v[i].y);
                }
            }
        }
        for(int i=0;i<=sumh;i++)ans=max(ans,dp[m][i]);
        printf("Case %d: %d\n",++cas,ans-1);
    }
    return 0;
}
