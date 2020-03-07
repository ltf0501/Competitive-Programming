#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
char s[maxn],t[maxn];
int L,k;
deque<int> dq[maxn],dq2;
int dp[maxn][maxn];
main()
{
    scanf("%s%s",s+1,t+1);
    scanf("%d%d",&L,&k);
    int n=strlen(s+1),m=strlen(t+1);
    for(int i=1;i<=m;i++)dp[0][i]=(i-1)/L+1,dq[i].push_back(0);
    for(int i=1;i<=n;i++)
    {
        dq2.clear();
        dq2.push_back(0);
        dp[i][0]=(i-1)/L+1;
        for(int j=1;j<=m;j++)
        {
            if(dq2.front()+L<j)dq2.pop_front();
            if(dq[j].front()+L<i)dq[j].pop_front();
            if(s[i]==t[j])dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=min(dp[i][dq2.front()],dp[dq[j].front()][j])+1;
            while(!dq2.empty())
            {
                int s=dq2.back();
                if(dp[i][s]>=dp[i][j])dq2.pop_back();
                else break;
            }
            dq2.push_back(j);
            while(!dq[j].empty())
            {
                int s=dq[j].back();
                if(dp[s][j]>=dp[i][s])dq[j].pop_back();
                else break;
            }
            dq[j].push_back(i);
        }
    }
    /*
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)printf("%d ",dp[i][j]);puts("");
    }
    */
    if(dp[n][m]>k)puts("Impossible");
    else printf("%d\n",dp[n][m]);
    return 0;
}
