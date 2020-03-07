#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 1000+5
vector<int> G[maxn];
int ti[maxn],n;
int dp[maxn];
int d(int u)
{
    if(dp[u])return dp[u];
    if(!G[u].size())return dp[u]=ti[u];
    int ans=0;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        ans=max(ans,d(v));
    }
    ans+=ti[u];
    return dp[u]=ans;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&ti[i]);
            int k;scanf("%d",&k);
            while(k--)
            {
                int y;
                scanf("%d",&y);
                G[i].push_back(y);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,d(i));
        printf("%d\n",ans);

    }
    return 0;
}
