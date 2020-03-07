#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
vector<int> g[maxn],v1,v2,v;
int n,m;
int in[maxn],out[maxn];
bool vis[maxn];
queue<int> q;
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y);
        out[x]++,in[y]++;
    }
    for(int i=1;i<=n;i++)if(!in[i])v1.push_back(i);
    for(int i=1;i<=n;i++)if(!out[i])v2.push_back(i);
    int sz=v1.size();
    for(int i=0;i<sz;i++)
    {
        memset(vis,0,sizeof(vis));
        vis[v1[i]]=1;
        q.push(v1[i]);
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int v : g[u])if(!vis[v])
                vis[v]=1,q.push(v);
        }
        int tmp=0;
        for(int j=0;j<sz;j++)
            if(vis[v2[j]])tmp|=(1<<j);
        v.push_back(tmp);
    }
    sz=v.size();
    for(int i=1;i<(1<<sz)-1;i++)
    {
        int tmp=0;
        for(int j=0;j<sz;j++)
            if(i&(1<<j))tmp|=v[j];
        if(__builtin_popcount(tmp)<=__builtin_popcount(i))
            return 0*puts("NO");
    }
    puts("YES");
    return 0;
}
