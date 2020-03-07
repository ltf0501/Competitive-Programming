#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 505
struct edge
{
    int v,d;
};
int p[maxn],tot[maxn],dp[maxn][maxn][2],vis[maxn];
vector<edge> g[maxn];
int dfs(int u,int fa)
{
    vis[u]=1;
    tot[u]=1;
    //統計子節點個數
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].v,d=g[u][i].d;
        if(vis[v] || v==fa)continue;
        tot[u]+=dfs(v,u);
        vis[v]=0;
    }
    dp[u][1][0]=dp[u][1][1]=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].v,d=g[u][i].d;
        if(vis[v] || v==fa)continue;
        for(int s=tot[u];s>=1;s--)
        {
            for(int j=1;j<=tot[v] && j<s;j++)
            {
                int tmp1=dp[u][s-j][1]+dp[v][j][0]+d;
                int tmp2=dp[u][s-j][0]+dp[v][j][1]+2*d;
                dp[u][s][0]=min(dp[u][s][0],min(tmp1, tmp2));
                dp[u][s][1]=min(dp[u][s][1],dp[u][s-j][1]+dp[v][j][1]+2*d);
            }
        }
    }
    return tot[u];
}
main()
{
    int n,cas=0;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)g[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            g[x].push_back((edge){y,d});
            g[y].push_back((edge){x,d});
        }
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        dfs(0,-1);
        int q;scanf("%d",&q);
        printf("Case %d:\n",++cas);
        while(q--)
        {
            int d;scanf("%d",&d);
            for(int i=n;i>=1;i--)
            {
                if(dp[0][i][0]<=d)
                {
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#define MP make_pair
using namespace std;

typedef pair<int, int> PII;
typedef long long int64;
const int INF = 0x3f3f3f3f;

const int MAXN = 510;

vector<PII >adj[MAXN];
int n, q;
int tot[MAXN];
int f[MAXN][MAXN][2];
bool vis[MAXN];

int dfs(int u) {
    vis[u] = true;

    tot[u] = 1;

    // 统计子树节点个数
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        int w = adj[u][i].second;
        if (vis[v]) continue;
        tot[u] += dfs(v);
        vis[v] = false;
    }

    // dp
    f[u][1][0] = f[u][1][1] = 0;
    for (int i = 0; i < adj[u].size(); ++i) {
        int v = adj[u][i].first;
        int w = adj[u][i].second;
        if (vis[v]) continue;
        for (int s = tot[u]; s >= 1; --s) {
            for (int j = 1; j <= tot[v] && j < s; ++j) {
                int tmp1 = f[u][s-j][1] + f[v][j][0] + w;
                int tmp2 = f[u][s-j][0] + f[v][j][1] + 2 * w;
                f[u][s][0] = min(f[u][s][0],  min(tmp1, tmp2));
                f[u][s][1] = min(f[u][s][1], f[u][s-j][1] + f[v][j][1] + 2 * w);
            }
        }
    }
    return tot[u];
}

int main(){

    int cas = 1;
    while (~scanf("%d", &n) && n) {

        // init
        for (int i = 0; i <= n; ++i)
            adj[i].clear();

        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            scanf("%d%d%d", &v, &u, &w);
            adj[u].push_back(MP(v, w));
        }

        memset(vis, 0, sizeof(vis));
        memset(f, INF, sizeof(f));
        dfs(0);

        scanf("%d", &q);
        printf("Case %d:\n", cas++);
        while (q--) {
            int d;
            scanf("%d", &d);
            for (int i = n; i >= 1; --i) {
                if (f[0][i][0] <= d) {
                    printf("%d\n", i);
                    break;
                }
            }
        }
    }
    return 0;
}
*/
