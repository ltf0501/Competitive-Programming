#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define maxn 105
vector<pii> g[maxn];
int n,m;
int dp[maxn][maxn][26];
int dfs(int i,int j,int c)
{
    if(dp[i][j][c])return dp[i][j][c];
    int ret=2;
    for(auto v : g[i])if(v.S>=c)
    {
        if(dfs(j,v.F,v.S)==2)ret=1;
    }
    return dp[i][j][c]=ret;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;char c[2];scanf("%d%d%s",&x,&y,c);
        g[x].push_back(pii(y,c[0]-'a'));
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dfs(i,j,0)==1)putchar('A');
            else putchar('B');
        }
        puts("");
    }
    return 0;
}
