#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
vector<int> g[maxn];
char c[maxn];
int n,val[maxn];
int dp[2][maxn],ans[maxn];
int cal(char c,int x,int y=-1)
{
    if(c=='N')return !x;
    if(c=='A')return x&y;
    if(c=='O')return x|y;
    if(c=='X')return x^y;
}
void dfs1(int u)
{
    int a[2],cnt=0;
    for(int v : g[u])
    {
        dfs1(v);
        a[cnt++]=val[v];
    }
    if(c[u]!='I')val[u]=cal(c[u],a[0],a[1]);
}
void dfs2(int u)
{
    if(c[u]=='I')
    {
        ans[u]=dp[val[u]^1][u];
        return ;
    }
    int a[2],cnt=0;
    for(int v : g[u])a[cnt++]=val[v];
    cnt=0;
    for(int v : g[u])
    {
        int tmp=a[cnt];
        for(int i=0;i<2;i++)
            a[cnt]=i,dp[i][v]=dp[cal(c[u],a[0],a[1])][u];
        a[cnt++]=tmp;
        dfs2(v);
    }
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        char buf[5];scanf("%s",buf);
        c[i]=buf[0];
        if(c[i]=='I')
        {
            int x;scanf("%d",&x);
            val[i]=x;
        }
        else if(c[i]=='N')
        {
            int x;scanf("%d",&x);
            g[i].push_back(x);
        }
        else
        {
            int x,y;scanf("%d%d",&x,&y);
            g[i].push_back(x),g[i].push_back(y);
        }
    }
    dfs1(1);
    //for(int i=1;i<=n;i++)printf("%d ",val[i]);puts("");
    dp[0][1]=0,dp[1][1]=1;
    memset(ans,-1,sizeof(ans));
    dfs2(1);
    /*
    for(int j=0;j<2;j++)
    {
        for(int i=1;i<=n;i++)printf("%d ",dp[j][i]);puts("");
    }
    */
    for(int i=1;i<=n;i++)
        if(ans[i]!=-1)printf("%d",ans[i]);
    return 0;
}
