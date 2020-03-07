#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define pii pair<int,int>
#define F first
#define S second
const int INF=2e9+7;
vector<pii> g[maxn];
pii p[maxn];
int n,k;
int d[maxn],mxer;
int pre[maxn],suf[maxn];
int len;
vector<pii> node;
bool flag[maxn];
void dfs1(int u,int fa,int dis)
{
    d[u]=dis;
    if(d[mxer]<dis)mxer=u;
    for(pii v : g[u])if(v.F!=fa)
        p[v.F]=pii(u,v.S),dfs1(v.F,u,dis+v.S);
}
void dfs2(int u,int fa,int dis)
{
    d[u]=dis;
    for(pii v : g[u])if(v.F!=fa)
        dfs2(v.F,u,dis+(flag[v.F] ? 0 : v.S));
}
int solve(int s)
{
    if(s<0 || s+k>len)return INF;
    memset(flag,0,sizeof(flag));
    memset(d,0,sizeof(d));
    for(int i=0;i<=k;i++)flag[node[s+i].F]=1;
    dfs2(node[s].F,0,0);
    int res=0;
    for(int i=1;i<=n;i++)res=max(res,d[i]);
    return res;
}
main()
{
    scanf("%d%d",&n,&k);k--;
    for(int i=1;i<n;i++)
    {
        int x,y,d;scanf("%d%d%d",&x,&y,&d);
        g[x].push_back(pii(y,d)),g[y].push_back(pii(x,d));
    }
    dfs1(1,0,0);
    int rt=mxer;mxer=0;
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)p[i]=pii(0,0);
    dfs1(rt,0,0);
    node.push_back(pii(mxer,0));
    while(p[mxer].F)node.push_back(p[mxer]),mxer=p[mxer].F;
    //for(pii s : node)printf("%d %d\n",s.F,s.S);
    len=node.size();len--;
    k=min(k,len);
    for(int i=1;i<=len;i++)pre[i]=pre[i-1]+node[i].S;
    for(int i=len;i>=1;i--)suf[i]=suf[i+1]+node[i].S;
    vector<int> ans;
    //printf("%d %d\n",k,len);
    for(int i=0;i<=len;i++)
    {
        if(pre[i]>suf[i+k+1])
        {
            ans.push_back(i);
            ans.push_back(i-1);
            break;
        }
        if(pre[i]==suf[i+k+1])
        {
            ans.push_back(i-1);
            ans.push_back(i);
            ans.push_back(i+1);
            break;
        }
    }
    //for(int s : ans)printf("%d ",s);puts("");
    int res=INF;
    for(int s : ans)res=min(res,solve(s));
    printf("%d\n",res);
    return 0;
}
