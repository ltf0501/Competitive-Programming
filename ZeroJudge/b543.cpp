#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 5000+10
struct Employee
{
    int a,b,c;
}e[maxn];
int n,vis[maxn];
vector<int> g[maxn];

void dfs(int u)
{
    if(vis[u])return ;
    vis[u]=1;
    for(int i=0;i<g[u].size();i++)
        dfs(g[u][i]);
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
            g[i].clear();
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(e[i].a>e[j].a && e[i].b>e[j].c)g[i].push_back(j);
                if(e[j].a>e[i].a && e[j].b>e[i].c)g[j].push_back(i);
            }
        }
        int s;scanf("%d",&s);
        dfs(s);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
