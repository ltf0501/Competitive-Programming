#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
const int mod=998244353;
int n,k;
int a[maxn];
vector<int> g[maxn];
int anc[20][maxn];
int in[maxn],out[maxn],dfs_clock;
int top[maxn];
ll dp[maxn][2];
void add(ll &a,ll b)
{
    a+=b;
    if(a>mod)a-=mod;
}
void pre_dfs(int u,int fa)
{
    in[u]=++dfs_clock;
    anc[0][u]=fa;
    for(int v : g[u])if(v!=fa)
        pre_dfs(v,u);
    out[u]=dfs_clock;
}
void pre()
{
    pre_dfs(1,0);out[0]=dfs_clock;
    for(int j=1;j<20;j++)
        for(int i=1;i<=n;i++)anc[j][i]=anc[j-1][anc[j-1][i]];
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=19;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x];
    return anc[0][x];
}
int dfs(int u,int fa)
{
    vector<pii> vv;
    for(int v : g[u])if(v!=fa)
    {
        int c=dfs(v,u);
        if(c!=0)vv.push_back(pii(c,v));
    }
    if(a[u]==0 && vv.empty())return 0;
    int need=-1;
    for(pii tmp : vv)if(tmp.F>0)
    {
        if(need!=-1 && need!=tmp.F)
        {
            //for(pii tt : vv)printf("val=%d son=%d\n",tt.F,tt.S);
            //printf("%d ",u);
            puts("0");exit(0);
        }
        need=tmp.F;
    }
    if(need!=-1 && a[u]!=0 && need!=a[u]){puts("0");exit(0);}
    if(a[u]==0 && need==-1)
    {
        vector<ll> pre,suf;
        pre.push_back(1ll),suf.push_back(1ll);
        ll tt=1;
        for(pii s : vv)tt=tt*((dp[s.S][0]+dp[s.S][1])%mod)%mod,pre.push_back(tt);
        tt=1;
        for(int i=(int)vv.size()-1;i>=0;i--)
            tt=tt*((dp[vv[i].S][0]+dp[vv[i].S][1])%mod)%mod,suf.push_back(tt);
        reverse(suf.begin(),suf.end());
        dp[u][0]=pre.back();
        for(int i=0;i<(int)vv.size();i++)
            add(dp[u][1],1ll*pre[i]*suf[i+1]%mod*dp[vv[i].S][1]%mod);
        return -1;
    }
    dp[u][1]=1;
    for(pii s : vv)
    {
        if(s.F==-1)dp[u][1]=dp[u][1]*((dp[s.S][0]+dp[s.S][1])%mod)%mod;
        else dp[u][1]=dp[u][1]*dp[s.S][1]%mod;
    }
    if(a[u]==0)return need;
    return top[a[u]]==u ? -1 : a[u];
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    pre();
    memset(top,-1,sizeof(top));
    for(int i=1;i<=n;i++)
        top[a[i]]=(top[a[i]]==-1 ? i : LCA(top[a[i]],i));
    for(int i=1;i<=k;i++)
    {
        if(a[top[i]]!=0 && a[top[i]]!=i)return 0*puts("0");
        a[top[i]]=i;
    }
    //for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
    //for(int i=1;i<=k;i++)printf("%d ",top[i]);puts("");
    dfs(1,0);
    printf("%lld\n",dp[1][1]);
    return 0;
}
/*
10 5
1 2 3 5 0 5 0 4 4 5
7 9
10 5
5 6
5 4
7 8
3 10
1 8
4 2
7 10
*/
