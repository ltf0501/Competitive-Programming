#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
char c[maxn];
int tmp[3];
int dp[maxn];
main()
{
    scanf("%s",c+1);
    int n=strlen(c+1);
    int now=0;
    tmp[1]=tmp[2]=-1;
    for(int i=1;i<=n;i++)
    {
        now=(now+c[i]-'0')%3;
        dp[i]=dp[i-1];
        if(tmp[now]!=-1)dp[i]=max(dp[i],dp[tmp[now]]+1);
        tmp[now]=i;
        //printf("%d ",dp[i]);
    }
    printf("%d\n",dp[n]);
    return 0;
}
