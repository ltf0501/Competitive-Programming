#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
vector<int> g[maxn];
int n,m;
int deg[maxn];
queue<pii> q;
bool vis[2][maxn];
int fa[2][maxn];
vector<int> ans;
int vis2[maxn];
bool check(int u)
{
    vis2[u]=1;
    for(int v : g[u])
    {
        if(vis2[v]==1)return 1;
        if(!vis2[v])
            if(check(v))return 1;
    }
    vis2[u]=2;
    return 0;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&deg[i]);
        for(int j=1;j<=deg[i];j++)
        {
            int x;scanf("%d",&x);
            g[i].push_back(x);
        }
    }
    int s;scanf("%d",&s);
    q.push(pii(0,s));
    vis[0][s]=1;
    fa[0][s]=fa[1][s]=-1;
    while(!q.empty())
    {
        pii t=q.front();q.pop();
        vis[t.F][t.S]=1;
        for(int v : g[t.S])
        {
            if(!vis[t.F^1][v])
            {
                fa[t.F^1][v]=t.S;
                vis[t.F^1][v]=1;
                q.push(pii(t.F^1,v));
            }
        }
    }
    bool win=0;
    for(int i=1;i<=n;i++)if(vis[1][i] && !deg[i])
    {
        win=1;
        int cur=1;
        while(i!=-1)
        {
            ans.push_back(i);
            i=fa[cur][i];
            cur^=1;
        }
        break;
    }
    if(!win)
        return 0*puts(check(s) ? "Draw" : "Lose");
    puts("Win");
    reverse(ans.begin(),ans.end());
    for(int s : ans)printf("%d ",s);
    return 0;
}
