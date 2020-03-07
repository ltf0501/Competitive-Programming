#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
vector<int> g[maxn];
int match[maxn];
bool vis[maxn];
int cnt;
struct P
{
    int t,x,y;
    void input()
    {
        scanf("%d%d%d",&t,&x,&y);
    }
}a[maxn];
bool dfs(int u)
{
    vis[u]=1;
    for(int v : g[u])if(!vis[match[v]])
    {
        if(!match[v] || dfs(match[v]))
        {
            if(!match[v])cnt++;
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=n;i++)a[i].input();
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
            if(i!=j && abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y)+a[i].t<=a[j].t)
                g[i].push_back(j);
        memset(match,0,sizeof(match));
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            dfs(i);
            memset(vis,0,sizeof(vis));
        }
        printf("%d\n",n-cnt);
    }
    return 0;
}
