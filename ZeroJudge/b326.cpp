#include<bits/stdc++.h>
using namespace std;
#define maxn 33000
vector<int> g[maxn];
int p[maxn];
bool d[maxn];
void dfs(int u,int fa)
{
    p[u]=fa;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==fa)continue;
        dfs(v,u);
    }
}
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)p[i]=-1;
        for(int i=0;i<n;i++)g[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            g[a].push_back(b);g[b].push_back(a);
        }
        dfs(0,-1);
        //for(int i=0;i<n;i++)printf("%d ",p[i]);puts("");
        int q;scanf("%d",&q);
        while(q--)
        {
            char c[2];int x;
            scanf("%s %d",c,&x);
            if(c[0]=='M')d[x]^=1;
            else
            {
                while(x!=-1)
                {
                    if(d[x])break;
                    x=p[x];
                }
                printf("%d\n",x);
            }
        }
        puts("");
    }
    return 0;
}
