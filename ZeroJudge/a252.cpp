#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define maxn 100+5
int dp[maxn][maxn][maxn];
int Max(int a,int b,int c)
{
    return max(a,max(b,c));
}
main()
{
    string s1,s2,s3;

    while(cin>>s1)
    {
        cin>>s2>>s3;
        int t1=s1.size(),t2=s2.size(),t3=s3.size();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=t1;i++)
        {
            for(int j=1;j<=t2;j++)
            {
                for(int k=1;k<=t3;k++)
                {
                    if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                    else dp[i][j][k]=Max(dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]);
                }
            }
        }
        printf("%d\n",dp[t1][t2][t3]);
    }
    return 0;
}
