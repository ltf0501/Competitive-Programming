#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define MOD 32768
#define maxn 2000+10
struct node
{
    int to,dis;
};
int num[maxn][200+10];
int d[maxn][200+10],m,n;
bool vis[maxn];
vector<node> G[maxn];
char name[200+10][200];
void dfs(int u)
{
    if(vis[u])return ;
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        node v=G[u][i];
        dfs(v.to);
        for(int j=1;j<=m;j++)
        {
            num[u][j]=(num[u][j]+num[v.to][j])%MOD;
            d[u][j]=(d[u][j]+num[v.to][j]*v.dis+d[v.to][j])%MOD;
        }
    }
    if(u>=1 && u<=m)num[u][u]++;
}
main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        int x;scanf("%d%d%d",&m,&n,&x);
        for(int i=0;i<maxn;i++)G[i].clear();
        for(int i=1;i<=m;i++)scanf("%s",name[i]);
        while(x--)
        {
            int x,y,dis;
            scanf("%d%d%d",&x,&y,&dis);
            dis%=MOD;
            G[x].push_back((node){y,dis});
        }
        memset(vis,false,sizeof(vis));
        memset(num,0,sizeof(num));
        memset(d,false,sizeof(d));
        dfs(0);
        printf("Game #%d\n",++cas);
        for(int i=1;i<=m;i++)printf("%s: %d\n",name[i],d[0][i]);
    }
    return 0;
}
