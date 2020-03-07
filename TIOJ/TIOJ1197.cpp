#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int> G[15];
int m,n,p[15],vis[15],cnt,flag;
long long ans;
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(vis[v])p[u]++;
    }
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!vis[v])dfs(v);
    }
    if(p[u]>=n)flag=0;
}
main()
{
    scanf("%d%d",&m,&n);
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ans=1,flag=1;
    for(int i=1;i<=m;i++)if(!vis[i])dfs(i);
    int M=0;
    /*
    for(int i=1;i<=m;i++)printf("%d ",p[i]);
    puts("");
    */
    for(int i=1;i<=m;i++)M=max(M,p[i]);
    if(!flag)
        printf("0\n%d\n",M+1);
    else
    {
        for(int i=1;i<=m;i++)ans*=(n-p[i]);
        printf("%lld\n%d\n",ans,M+1);
    }
    return 0;
}
