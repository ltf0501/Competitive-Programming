#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn];
int n,m;
int col[maxn];
vector<int> v[3];
bool dfs(int u,int c)
{
    col[u]=c;
    v[c].push_back(u);
    for(int s : g[u])
    {
        if(!col[s])
        {
            if(!dfs(s,3-c))return 0;
        }
        else if(col[s]==c)return 0;
    }
    return 1;
}

main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)if(!col[i])
    {
        if(!dfs(i,1))return 0*puts("-1");
    }
    printf("%d\n",v[1].size());
    for(int s : v[1])printf("%d ",s);puts("");
    printf("%d\n",v[2].size());
    for(int s : v[2])printf("%d ",s);puts("");
    return 0;
}
