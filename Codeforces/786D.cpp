#include<bits/stdc++.h>
using namespace std;
#define maxn 20010
#define pii pair<int,int>
#define F first
#define S second
vector<pii> g[maxn],que[maxn];
pii p[maxn];
int st[maxn];
int n,q;
int ans[maxn];
int dep[maxn],ch[maxn<<1],comp[maxn];
int vis[maxn],now;
void dfs(int u,int fa)
{
    for(pii v : g[u])if(v.F!=fa)
        p[v.F]=pii(u,v.S),dfs(v.F,u);
}
int check(int u,int v)
{
    now++;
    dep[v]=n;
    int cur=v,ret=-1;
    while(cur!=u)
    {
        //printf("cur = %d\n",cur);
        ch[dep[cur]]=p[cur].S;
        vis[cur]=now;
        comp[cur]=1;
        dep[p[cur].F]=dep[cur]-1;
        cur=p[cur].F;
        ret++;
    }
    vis[u]=now,comp[u]=1;
    for(int i=1;i<=n;i++)if(vis[i]!=now)
    {
        int top=0,cur=i;
        while(vis[cur]!=now)st[top++]=cur,cur=p[cur].F;
        for(int j=top-1;j>=0;j--)
        {
            int w=st[j];
            dep[w]=dep[p[w].F]+1;
            vis[w]=now;
            if(comp[p[w].F]!=1)comp[w]=comp[p[w].F];
            else if(p[w].S==ch[dep[w]])comp[w]=1;
            else if(p[w].S<ch[dep[w]])comp[w]=0;
            else comp[w]=2;
            if(comp[w]==0 || (comp[w]==1 && dep[w]<dep[v]))
                ret++;
            //printf("%d ",w);
        }
        //puts("");
    }
    return ret;
}
void solve(int u,int fa)
{
    //printf("now = %d\n",u);
    //for(int i=1;i<=n;i++)
    //    printf("%d: (%d,%c)\n",i,p[i].F,p[i].S);
    for(pii v : que[u])ans[v.S]=check(u,v.F);
    int tmp=p[u].S;
    for(pii v : g[u])if(v.F!=fa)
    {
        p[u]=v;
        solve(v.F,u);
    }
    p[u]=pii(fa,tmp);
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int x,y;char c[2];
        scanf("%d%d%s",&x,&y,c);
        g[x].push_back(pii(y,c[0])),g[y].push_back(pii(x,c[0]));
    }
    dfs(1,0);
    for(int i=1;i<=q;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        que[x].push_back(pii(y,i));
    }
    solve(1,0);
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}
