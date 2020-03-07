#include<bit/stdc++.h>
using namespace std;
#define maxn 1000+10
#define INF 1000000000
int dp[maxn];
bool vis[maxn][105];
main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(vis,false,sizeof(vis));
        memset(dp,INF,sizeof(INF));
        int b,e;scanf("%d%d",&b,&e);
        int k;scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            int p,q;scanf("%d%d",&p,&q);
            vis[p][q]=1;
        }
        dp[n-1][e]=0;
    }
    return 0;
}
