#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+5
#define INF 1000000000
int dp[maxn];
main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        fill(dp+1,dp+n+1,INF);
        for(int i=0;i<n;i++)
        {
            int r,d,p;scanf("%d%d%d",&r,&d,&p);
            for(int j=i;j>=0;j--)
            {
                int mx=max(dp[j]+1,r);
                if(mx+p-1<=d && dp[j+1]>=mx+p-1)dp[j+1]=mx+p-1;
            }
        }
        for(int i=n;i>=0;i--)
            if(dp[i]!=INF){printf("%d\n",i);break;}
    }
    return 0;
}
