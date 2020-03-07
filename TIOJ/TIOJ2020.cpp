#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int dfs(int x,int y)
{
    if(x<=0 || y<=0)return (int)1e7;
    if(x>y)swap(x,y);
    if(x==y)return 1;
    if(dp[x][y]>=0)return dp[x][y];
    int ans=(int)1e7;
    for(int i=1;i<x;i++)ans=min(ans,dfs(i,y)+dfs(x-i,y));
    for(int i=1;i<y;i++)ans=min(ans,dfs(x,i)+dfs(x,y-i));
    return dp[x][y]=ans;
}
main()
{
    int n,m;scanf("%d%d",&n,&m);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dfs(n,m));
    return 0;
}
