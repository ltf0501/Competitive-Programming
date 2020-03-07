#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
vector<int> v;
int n;
int dp[maxn][maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(i==1 || x!=v.back())v.push_back(x);
    }
    n=(int)v.size();
    for(int len=1;len<=n;len++)for(int i=0;i+len<n;i++)
    {
        int j=i+len;
        if(v[i]==v[j])dp[i][j]=dp[i+1][j-1]+1;
        else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;
    }
    printf("%d\n",dp[0][n-1]);
    return 0;
}
