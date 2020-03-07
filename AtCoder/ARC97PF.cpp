#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,bb,k;
vector<int> g[maxn];
char c[maxn];
bool isw[maxn],flag[maxn];
int sz[maxn],val[maxn];
int dp[2][maxn];
void dfs1(int u,int fa)
{
    sz[u]=isw[u];
    for(int v : g[u])if(v!=fa)
    {
        dfs1(v,u);
        sz[u]+=sz[v];
    }
}
void dfs2(int u,int fa)
{
    for(int v : g[u])if(v!=fa && sz[v])
    {
        dfs2(v,u);
        flag[u]^=1;
        bb++;
    }
    if(flag[u]^isw[u]^(u!=fa))k++;
}
void dfs3(int u,int fa)
{
    int mx=0,secmx=0;
    for(int v : g[u])if(v!=fa && sz[v])
    {
        dfs3(v,u);
        if(dp[0][v]>mx)secmx=mx,mx=dp[0][v];
        else if(dp[0][v]>secmx)secmx=dp[0][v];
    }
    dp[0][u]=val[u]+mx;
    dp[1][u]=val[u]+secmx;
}
int dfs4(int u,int fa)
{
    int ret=0;
    for(int v : g[u])if(v!=fa && sz[v])
        ret=max(ret,dfs4(v,u));
    ret=max(ret,dp[0][u]+dp[1][u]-val[u]);
    return ret;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    scanf("%s",c+1);
    for(int i=1;i<=n;i++)isw[i]=(c[i]=='W');
    int root=0;
    for(int i=1;i<=n;i++)
        if(isw[i]){root=i;break;}
    if(!root)return 0*puts("0");
    dfs1(root,root);
    dfs2(root,root);
    for(int i=1;i<=n;i++)val[i]=flag[i]^isw[i]^(i!=root);
    dfs3(root,root);
    int tmp=dfs4(root,root);
    printf("%d\n",2*bb+k-2*tmp);
    return 0;
}
