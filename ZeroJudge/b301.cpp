#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 10000+5
vector<int> G[maxn];
int a[maxn][20],t,n;//a[u][i]表示u的上(1<<i)輩父親
int t_in[maxn],t_out[maxn];
void dfs(int u,int fa)
{
    t_in[u]=t++;
    //a[u][0]=fa;
    //for(int i=1;(1<<i)<n/2;i++)a[u][i]=a[a[u][i-1]][i-1];

    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(v==fa)continue;
        dfs(v,u);
    }
    t_out[u]=t++;
}/*
int log2(int n)
{
    int i=0;
    while((1<<i)<=n)i++;
    return i-1;
}
*/
bool ancestor(int x,int y)//判斷x是否為y的祖先
{
    return t_in[x]<t_in[y] && t_out[x]>t_out[y];
}
/*
int LCA(int x,int y)//找到x,y的最低公共祖先
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;

    for(int i=log2(n/2);i>=0;i--)
    {
        if(!ancestor(a[x][i],y))x=a[x][i];
    }
    return a[x][0];
}
*/
main()
{
    int q;
    while(scanf("%d%d",&n,&q)==2)
    {
        for(int i=0;i<=n;i++)G[i].clear();
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
        t=0;
        dfs(0,-1);
        while(q--)
        {
            int W,X,Y,Z;
            scanf("%d%d%d%d",&W,&X,&Y,&Z);
            if(t_in[Y]<t_in[Z])swap(Y,Z);
            if(ancestor(Y,W)^ancestor(Y,X))puts("GO");
            else puts("STOP");
        }
    }
    return 0;
}
