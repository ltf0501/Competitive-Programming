#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define pii pair<ll,ll>
#define F first
#define S second
const ll INF=1e16;
char ss(char c)
{
    if('A'<=c && c<='Z')return c-'A'+'a';
    return c;
}
struct P
{
    string s;
    pii p;
    void input()
    {
        p=pii(0,0);
        cin>>s;
        for(int i=0;i<s.size();i++)s[i]=ss(s[i]);
        for(int i=0;i<s.size();i++)if(s[i]=='r')p.F++;
        p.S=s.size();
    }
    bool operator < (const P& b)const
    {
        if(p!=b.p)return p<b.p;
        return s<b.s;
    }
}a[maxn],x[maxn],y[maxn];
map<P,int> mp;
map<int,P> mp2;
vector<int> g[maxn*3];
int in[maxn*3],dfs_clock=0;
int sccno[maxn*3],scc_cnt=0;
pii d[maxn*3];
stack<int> s;
int dfs(int u)
{
    s.push(u);
    in[u]=++dfs_clock;
    int lowu=dfs_clock;
    for(int v : g[u])
    {
        if(!in[v])lowu=min(lowu,dfs(v));
        else if(!sccno[v])lowu=min(lowu,in[v]);
    }
    if(lowu==in[u])
    {
        scc_cnt++;
        while(1)
        {
            int x=s.top();s.pop();
            d[scc_cnt]=min(d[scc_cnt],mp2[x].p);
            ///printf("%I64d ",mp2[x].val);
            sccno[x]=scc_cnt;
            if(x==u)break;
        }
        ///puts("");
    }
    return lowu;
}
int N=0;
vector<int> scc_g[maxn];
void build()
{
    for(int u=1;u<=N;u++)for(int v : g[u])
        if(sccno[u]!=sccno[v])scc_g[sccno[u]].push_back(sccno[v]);
    for(int i=1;i<=scc_cnt;i++)scc_g[scc_cnt+1].push_back(i);
}
bool vis[maxn*3];pii dp[maxn*3];
pii dfs2(int u)
{
    if(vis[u])return dp[u];
    vis[u]=1;
    pii ret=d[u];
    ///printf("dp[%d] = %I64d\n",u,ret);
    for(int v : scc_g[u])ret=min(ret,dfs2(v));
    ///printf("dp[%d]=%I64d\n",u,ret);
    return dp[u]=ret;
}
int p[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        a[i].input();
        if(mp.find(a[i])==mp.end())mp[a[i]]=++N,mp2[N]=a[i];
        p[i]=mp[a[i]];
    }
    int m;scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        x[i].input(),y[i].input();
        if(mp.find(x[i])==mp.end())mp[x[i]]=++N,mp2[N]=x[i];
        if(mp.find(y[i])==mp.end())mp[y[i]]=++N,mp2[N]=y[i];
        g[mp[x[i]]].push_back(mp[y[i]]);
        ///printf("%d %d\n",mp[x[i]],mp[y[i]]);
    }
    for(int i=1;i<=N;i++)d[i]=pii(INF,INF);
    /*
    for(int i=1;i<=N;i++)
    {
        ///printf("%I64d\n",mp2[i].val);
        printf("%d: ",i);
        for(int v : g[i])printf("%d ",v);puts("");
    }
    */
    for(int i=1;i<=N;i++)
        if(!in[i])dfs(i);
    ///for(int i=1;i<=N;i++)printf("%d ",sccno[i]);puts("");
    ///printf("%d\n",scc_cnt);
    build();
    ///for(int i=1;i<=scc_cnt;i++)printf("%I64d %I64d\n",d[i].F,d[i].S);
    ll ans1=0,ans2=0;
    dfs2(scc_cnt+1);
    /*
    for(int i=1;i<=scc_cnt;i++)
        if(!vis[i])dfs2(i);
    */
    ///for(int i=1;i<=n;i++)printf("%d ",p[i]);
    for(int i=1;i<=n;i++)
    {
        int x=sccno[p[i]];
        ///printf("%d %I64d\n",x,dp[x]);
        ///printf("%I64d %I64d\n",dp[x].F,dp[x].S);
        ans1+=dp[x].F,ans2+=dp[x].S;
    }
    printf("%I64d %I64d\n",ans1,ans2);
    return 0;
}
/*
7
raki vezde est awjgkawkgjn ttttt raki raks
4
raks rks
rks raks
raki raks
vezde pss
*/
