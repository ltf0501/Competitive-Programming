#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[20][105];
int l[20],r[20];
int dp[2][20];
main()
{
    scanf("%d%d",&n,&m);
    int k=-1,s=-1;
    memset(l,-1,sizeof(l));memset(r,-1,sizeof(r));
    for(int i=n-1;i>=0;i--)scanf("%s",c[i]);
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            if(c[i][j]=='1')
            {
                if(s==-1)s=i;
                r[i]=j;
                if(l[i]==-1)l[i]=j;
                k=i;
            }
        }
    }
    if(k==-1){puts("0");return 0;}

    dp[0][s]=2*r[s]-l[s];
    dp[1][s]=r[s];

    int c=0;
    for(int i=s+1;i<=k;i++)
    {
        if(l[i]!=-1)
        {
            dp[0][i]=min(dp[0][i-1-c]+l[i-1-c]+1+c+2*r[i]-l[i],dp[1][i-1-c]+(m+1-r[i-1-c])+1+c+(m+1-l[i]));
            dp[1][i]=min(dp[0][i-1-c]+l[i-1-c]+1+c+r[i],dp[1][i-1-c]+(m+1-r[i-1-c])+1+c+2*(m+1-l[i])-(m+1-r[i]));
            c=0;
        }
        else c++;
       // printf("%d %d %d %d\n",l[i],r[i],dp[0][i],dp[1][i]);
    }
    printf("%d\n",min(dp[0][k],dp[1][k])+s);
    return 0;
}
