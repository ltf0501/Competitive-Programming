#include<bits/stdc++.h>
using namespace std;
#define maxn 1000+10
#define INF 1000000000
vector<int> g[maxn];
bool infe[maxn];
int dp[2][maxn][maxn],dp2[maxn][maxn];
int sz[maxn];
void dfs(int u,int fa)
{
    sz[u]=1;
    if(u && (int)g[u].size()==1)
    {
        if(!infe[u])dp[0][u][0]=1,dp[1][u][0]=0;
        else dp[0][u][0]=-INF,dp[1][u][0]=0;
        return ;
    }
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        dfs(v,u),sz[u]+=sz[v];
    }
    for(int c=0;c<2;c++)
    {
        if(c==0 && infe[u])
        {
            for(int i=0;i<sz[u];i++)dp[c][u][i]=-INF;
            continue;
        }
        for(int i=0;i<sz[u];i++)dp2[0][i]=-INF;
        dp2[0][0]=0;
        int cnt=0,tot=0;
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(v==fa)continue;
            tot+=sz[v];
            for(int j=0;j<sz[u];j++)dp2[cnt+1][j]=-INF;
            for(int j=(c!=0);j<=tot;j++)
                for(int k=0;k<sz[v] && j-k-(c!=0)>=0;k++)
                    dp2[cnt+1][j]=max(dp2[cnt+1][j],dp2[cnt][j-k-(c!=0)]+dp[0][v][k]);
            for(int j=(c!=1);j<=tot;j++)
                for(int k=0;k<sz[v] && j-k-(c!=1)>=0;k++)
                    dp2[cnt+1][j]=max(dp2[cnt+1][j],dp2[cnt][j-k-(c!=1)]+dp[1][v][k]);
            cnt++;
        }
        for(int i=0;i<sz[u];i++)
            dp[c][u][i]=(!c)+dp2[cnt][i];
    }
}
main()
{
    int n,k,num;
    while(~scanf("%d%d%d",&n,&k,&num))
    {
        memset(infe,false,sizeof(infe));
        for(int i=0;i<n;i++)g[i].clear();
        for(int i=1;i<=num;i++)
        {
            int x;scanf("%d",&x);
            infe[x]=1;
        }
        for(int i=0;i<n-1;i++)
        {
            int x,y;scanf("%d%d",&x,&y);
            g[x].push_back(y),g[y].push_back(x);
        }
        if(k+num>n){puts("ACM Rules!");continue;}

        dfs(0,-1);
        int ans1=n-1,ans2=n-1;
        for(int i=0;i<n;i++)
            if(dp[0][0][i]>=k){ans1=i;break;}
        for(int i=0;i<n;i++)
            if(dp[1][0][i]>=k){ans2=i;break;}
        printf("%d\n",min(ans1,ans2));
    }
    return 0;
}
