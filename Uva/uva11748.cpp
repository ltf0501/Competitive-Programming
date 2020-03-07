#include<algorithm>
#include <cstdio>
#include <cstring>
#include<vector>
using namespace std;
#define MAXN 105
int n,m,c;
int A[MAXN][MAXN];
vector<int> G[MAXN];
int vis[MAXN];

void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(vis[v])continue;
        dfs(v);
    }

}

main()
{
    while(scanf("%d %d %d",&n,&m,&c)==3)
    {
        if(n==0 && m==0 && c==0)break;
        int a;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a);
                A[i][a]=j;
            }
        }
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int cnt=0;
                for(int k=1;k<=m;k++)
                {
                    if(A[k][i]<A[k][j])cnt++;
                }
                if(cnt>m/2)G[i].push_back(j);
                else G[j].push_back(i);
            }
        }
        memset(vis,0,sizeof(vis));
        dfs(c);
        int cnt=0;
        for(int i=1;i<=n;i++){if(vis[i])cnt++;}
        if(cnt==n)printf("yes\n");
        else printf("no\n");

    }
    return 0;
}
