#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 1000000+5
int vis[maxn],sccno[maxn],scc_cnt,n,m;
vector<int> G[maxn],G2[maxn],S;
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
        if(!vis[G[u][i]])dfs(G[u][i]);
    S.push_back(u);
}
void dfs2(int u)
{
    sccno[u]=scc_cnt;
    for(int i=0;i<G2[u].size();i++)
        if(!sccno[G2[u][i]])dfs2(G2[u][i]);
}
main()
{
    scc_cnt=0;
    scanf("%d%d",&n,&m);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[y].push_back(x);
        G2[x].push_back(y);
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
    for(int i=n-1;i>=0;i--)if(!sccno[S[i]]){scc_cnt++;dfs2(S[i]);}
    printf("%d\n",scc_cnt);
    for(int i=1;i<=n;i++)
        printf("%d ",scc_cnt-sccno[i]+1);
    puts("");
    return 0;
}
