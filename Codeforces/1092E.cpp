#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
#define pii pair<int,int>
#define F first
#define S second
vector<int> g[maxn],tmp,mid;
vector<pii> ans;
int idx,mx;
int n,m;
int p[maxn];
bool vis[maxn];
pii dfs(int u,int fa,int dep)
{
    pii res=pii(dep,u);
    vis[u]=1;p[u]=fa;
    for(int v : g[u])if(v!=fa)
        res=max(res,dfs(v,u,dep+1));
    return res;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)if(!vis[i])
    {
        pii a=dfs(i,0,0);
        pii b=dfs(a.S,0,0);
        tmp.clear();
        int cur=b.S;
        while(cur!=a.S)tmp.push_back(cur),cur=p[cur];
        tmp.push_back(a.S);
        //for(int j : tmp)printf("%d ",j);puts("");
        int umr=tmp[(int)tmp.size()/2];
        if(tmp.size()>mx)
        {
            mx=tmp.size();
            idx=umr;
        }
        mid.push_back(umr);
    }
    for(int i : mid)if(i!=idx)ans.push_back(pii(i,idx)),g[i].push_back(idx),g[idx].push_back(i);
    pii a=dfs(1,0,0);
    pii b=dfs(a.S,0,0);
    printf("%d\n",b.F);
    for(pii e : ans)printf("%d %d\n",e.F,e.S);
    return 0;
}
