#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 10000+5
int dp[maxn],A[maxn],D[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int W,B,n;
        scanf("%d%d%d",&W,&B,&n);
        for(int i=1;i<=n;i++)scanf("%d%d",&A[i],&D[i]);
        int M;
        scanf("%d",&M);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=W;i++)
            for(int j=1;j<=n;j++)
                if(A[j]+M<i)dp[i]=max(dp[i],dp[i-A[j]-M]+D[j]);

        if(dp[W]<B)puts("No");
        else puts("Yes");
    }
    return 0;
}
