#include<bits/stdc++.h>
using namespace std;
const int maxn=105,maxm=205;
int dp[maxm][maxm][maxn];
int m,n,a,b,c,d;
int f(int i,int x,int y){return (a*i+b*x+c*y)%d;}
main()
{
    scanf("%d%d%d%d%d%d",&m,&n,&a,&b,&c,&d);
    if(n>m){puts("0");return 0;}
    for(int x=1;x<=m;x++)for(int y=1;y<=m;y++)
    {
        for(int i=1;i<=min(x,n);i++)
        {
            dp[x][y][i]=dp[x-1][y-1][i-1]+f(i-1,x-1,y-1);
            dp[x][y][i]=max({dp[x][y][i],dp[x-1][y][i],dp[x][y-1][i]});
        }
    }
    printf("%d\n",dp[m][m][n]);
    return 0;
}
