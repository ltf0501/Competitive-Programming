#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 1000
vector<int> G[maxn];
int vis[maxn];
void dfs(int a)
{
    vis[a]=1;
    for(int i=0;i<G[a].size();i++)
    {
        int u=G[a][i];
        if(vis[u])continue;
        else dfs(u);
    }
}
main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)G[i].clear();
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
        }
        int A,B;
        scanf("%d%d",&A,&B);
        dfs(A);
        if(vis[B])printf("Yes!!!\n");
        else printf("No!!!\n");
    }
    return 0;
}
