#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
double dp[maxn];
int sz[maxn];
vector<int> g[maxn];
int dfs1(int u,int fa)
{
    int ret=1;
    for(int v : g[u])if(v!=fa)
    {
        ret+=dfs1(v,u);
    }
    return sz[u]=ret;
}
double dfs2(int u,int fa)
{
    int cnt=0;
    double sum=0.0;
    for(int v : g[u])if(v!=fa)
    {
        sum+=dfs2(v,u)+1;
        cnt++;
    }
    if(!cnt)return 0;
    return sum/cnt;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)dp[i]=0.0;
    dfs1(1,0);
    double ans=dfs2(1,0);
    printf("%.6f\n",ans);
    return 0;
}
