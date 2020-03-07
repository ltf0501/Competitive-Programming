#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
vector<int> g[maxn];
int n;
int maxv,maxd;
void dfs(int u,int fa,int d)
{
    if(d>maxd)maxd=d,maxv=u;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        dfs(v,u,d+1);
    }
}
main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)g[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        maxd=0;
        dfs(0,-1,0);
        maxd=0;
        dfs(maxv,-1,0);
        printf("%d\n",maxd);
    }
    return 0;
}


