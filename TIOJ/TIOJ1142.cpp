#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
vector<int> g1[maxn],g2[maxn];
int a[maxn],dp[maxn],in[maxn];
queue<int> q;
bool vis[maxn];
int dfs(int u)
{
    vis[u]=1;
    int sum=1;
    for(int v : g2[u])
        if(!vis[v])sum+=dfs(v);
    return sum;
}
main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),dp[i]=a[i];
        memset(in,0,sizeof(in));
        for(int i=1;i<=n;i++)g1[i].clear(),g2[i].clear();
        for(int i=1;i<=m;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            g1[x].push_back(y);
            in[y]++;
        }
        for(int i=1;i<=n;i++)if(!in[i])q.push(i);
        int mx=0;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            if(!g1[u].size())
            {
                if(dp[u]>mx)
                {
                    mx=dp[u];
                    g2[0].clear();
                    g2[0].push_back(u);
                }
                else if(dp[u]==mx)g2[0].push_back(u);
                continue;
            }
            for(int v : g1[u])
            {
                if(dp[u]+a[v]>dp[v])
                {
                    dp[v]=dp[u]+a[v];
                    g2[v].clear();
                    g2[v].push_back(u);
                }
                else if(dp[u]+a[v]==dp[v])
                    g2[v].push_back(u);
                if(!(--in[v]))q.push(v);
            }
        }
        //for(int i=1;i<=n;i++)printf("%d ",dp[i]);puts("");
        printf("%d\n",dfs(0)-1);
        /*
        for(int u=0;u<=n;u++)
        {
            for(int v : g2[u])printf("%d ",v);
            puts("");
        }
        */
    }

    return 0;
}
