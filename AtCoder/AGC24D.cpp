#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define pii pair<int,int>
#define F first
#define S second
int n;
vector<int> g[maxn];
int deg[maxn],dep[maxn];
bool vis[maxn];
queue<pii> q;
main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
        deg[x]++,deg[y]++;
    }
    for(int i=1;i<=n;i++)if(deg[i]==1)
    {
        q.push(pii(i,1));
    }
    int ans=0;
    while(!q.empty())
    {
        pii t=q.front();q.pop();
        printf("%d: %d\n",t.F,t.S);
        dep[t.F]=t.S,ans=t.S;
        vis[t.F]=1;
        for(int v : g[t.F])if(!vis[v])
        {
            deg[v]--;
            if(deg[v]==1)q.push(pii(v,t.S+1));
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",dep[i]);puts("");
    printf("%d\n",ans);
    return 0;
}
