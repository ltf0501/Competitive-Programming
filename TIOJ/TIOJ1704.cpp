#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 3000+5
#define INF 10000000
int w[maxn],wi[maxn],wc[maxn];
int a[maxn][maxn];
int dp[maxn],t[maxn];
int cmp(int a,int b)
{
    return w[a]<w[b];
}
main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
        wi[i]=i;
    }
    sort(wi,wi+n,cmp);
    for(int i=0;i<n;i++)wc[wi[i]]=i;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&a[wc[i]][j]);
    }
    fill(dp,dp+n,-INF);dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)t[j]=dp[j];
        for(int j=1;j<=n;j++)
        {
            if(t[j-1]!=-INF)dp[j]=max(dp[j],dp[j-1]+a[i][j-1]);
        }
    }
    for(int i=0;i<=n;i++)
        if(dp[i]>=k)
        {
            printf("%d\n",i);
            return 0;
        }
    puts("-1");
}
