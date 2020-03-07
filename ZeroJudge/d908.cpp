#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
vector<pii> g[30];
int dp[30];
int dfs(int u)
{
    if(dp[u])return dp[u];
    int ans=0;
    for(pii v : g[u])
    {
        ans=max(ans,dfs(v.F)+v.S);
    }
    return dp[u]=ans;
}
main()
{
    char c;scanf("%c",&c);
    int m;scanf("%d",&m);
    while(m--)
    {
        char x,y;
        int d;
        cin>>x>>y>>d;
        g[x-'A'].push_back(mkp(y-'A',d));
    }
    dfs(c-'A');
    int ans=0;
    for(int i=0;i<26;i++)ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}
