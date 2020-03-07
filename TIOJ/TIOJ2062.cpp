#include<cstdio>
#include<vector>
using namespace std;
#define maxn 1000010
int col[maxn];
vector<int> g[maxn],ans[2];
int n,m;
bool dfs(int u,int d)
{
    col[u]=d;
    ans[d&1].push_back(u);
    for(int v : g[u])
    {
        if(col[v]==d)return 0;
        else if(!col[v])
        {
            if(!dfs(v,3-d))return 0;
        }
    }
    return 1;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)if(!col[i])
    {
        if(!dfs(i,1))return 0*puts("-1");
    }
    printf("%d %d\n",ans[0].size(),ans[1].size());
    for(int s : ans[0])printf("%d ",s);puts("");
    for(int s : ans[1])printf("%d ",s);puts("");
    return 0;
}
