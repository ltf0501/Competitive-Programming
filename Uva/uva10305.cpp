#include<bits/stdc++.h>
using namespace std;

const int maxn=105;
int c[maxn],topo[maxn],t,n,m;
int G[maxn][maxn];
bool dfs(int u)
{
    c[u]=-1;
    for(int v=1;v<=n;v++)
    {
        if(G[u][v])
        {
            if(c[v]<0)return false;
            else if((!c[v])&&(!dfs(v)))return false;
        }
    }
    c[u]=1;
    topo[--t]=u;
    return true;
}
bool toposort()
{
    t=n;
    memset(c,0,sizeof(c));
    for(int u=1;u<=n;u++)
    {
        if(!c[u]){if(!dfs(u))return false;}
    }
    return true;
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&n+m)
    {
        memset(G,0,sizeof(G));
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x][y]=1;
        }
        if(toposort())
        {
            for(int i=0;i<n;i++)
            {
                if(i)printf(" ");
                printf("%d",topo[i]);
            }
            printf("\n");
        }
    }
}

