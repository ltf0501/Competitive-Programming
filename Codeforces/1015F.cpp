#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 205
const int mod=1e9+7;
string s;
int nxt[2][maxn];
ll dp[maxn][maxn][maxn];
main()
{
    int n;scanf("%d",&n);
    cin>>s;
    int m=s.size();
    for(int i=0;i<m;i++)
    {
        if(s[i]=='(')
        {
            nxt[0][i]=i+1;
            for(int j=0;j<i;j++)if(s.substr(j,i-j)+')'==s.substr(0,i-j+1))
            {
                nxt[1][i]=i-j+1;break;
            }
        }
        else
        {
            nxt[1][i]=i+1;
            for(int j=0;j<=i;j++)if(s.substr(j,i-j)+'('==s.substr(0,i-j+1))
            {
                nxt[0][i]=i-j+1;break;
            }
        }
    }
    nxt[0][m]=nxt[1][m]=m;
    //for(int i=0;i<=m;i++)printf("%d ",nxt[0][i]);puts("");
    //for(int i=0;i<=m;i++)printf("%d ",nxt[1][i]);puts("");
    dp[0][0][0]=1;
    for(int i=0;i<2*n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=m;k++)
    {
        int a=nxt[0][k],b=nxt[1][k];
        dp[i+1][j+1][a]=(dp[i+1][j+1][a]+dp[i][j][k])%mod;
        if(j)dp[i+1][j-1][b]=(dp[i+1][j-1][b]+dp[i][j][k])%mod;
    }
    printf("%lld\n",dp[2*n][0][m]);
    return 0;
}
