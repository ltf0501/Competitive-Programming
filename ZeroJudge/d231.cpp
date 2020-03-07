#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
#define maxn 50+5
string s1,s2;
int dp[maxn][maxn];
int pre[maxn][maxn];
void backtrack(int p,int q)
{
    if(p==0 || q==0)return;
    if(pre[p][q]==2)
    {
        backtrack(p-1,q-1);
        cout<<s1[p-1];
    }
    else if(pre[p][q]==1)
        backtrack(p-1,q);
    else
        backtrack(p,q-1);
}
main()
{
    while(cin>>s1>>s2)
    {
        int t1=s1.size(),t2=s2.size();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=t1;i++)
        {
            for(int j=1;j<=t2;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    pre[i][j]=2;
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else if(dp[i-1][j]>dp[i][j-1])
                {
                    dp[i][j]=dp[i-1][j];
                    pre[i][j]=1;
                }
                else
                {
                    dp[i][j]=dp[i][j-1];
                    pre[i][j]=3;
                }
            }
        }
        if(dp[t1][t2]==0)puts("E");
        else
        {
            backtrack(t1,t2);
        }
    }
    return 0;
}
