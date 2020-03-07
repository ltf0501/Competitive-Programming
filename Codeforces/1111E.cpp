#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
const int mod=1e9+7;
vector<int> g[maxn];
bool flag[maxn];
int n,q;
int f[maxn];
ll dp[maxn];
int bit[maxn];
void update(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    int res=0;
    for(int i=x;i;i-=i&-i)res+=bit[i];
    return res;
}
void add(ll &a,ll b)
{
    a+=b;
    if(a>=mod)a-=mod;
}
void sub(ll &a,ll b)
{
    a-=b;
    if(a<=0)a+=mod;
}
int anc[20][maxn],in[maxn],out[maxn],dfs_clock;
void pre_dfs(int u,int fa)
{
    anc[0][u]=fa;
    in[u]=++dfs_clock;
    for(int v : g[u])if(v!=fa)
        pre_dfs(v,u);
    out[u]=dfs_clock;
}
void pre()
{
    pre_dfs(1,0);out[0]=dfs_clock;
    for(int j=1;j<=17;j++)
        for(int i=1;i<=n;i++)anc[j][i]=anc[j-1][anc[j-1][i]];
}
bool ancestor(int x,int y){return in[x]<=in[y] && out[x]>=out[y];}
int LCA(int x,int y)
{
    if(ancestor(x,y))return x;
    if(ancestor(y,x))return y;
    for(int i=17;i>=0;i--)if(!ancestor(anc[i][x],y))
        x=anc[i][x];
    return anc[0][x];
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    pre();
    while(q--)
    {
        int k,m,r;scanf("%d%d%d",&k,&m,&r);
        vector<int> v;
        for(int i=1;i<=k;i++)
        {
            int x;scanf("%d",&x);
            v.push_back(x);
            flag[x]=1;
            update(in[x],1),update(out[x]+1,-1);
        }
        int tmp=query(in[r]);
        for(int i=0;i<k;i++)
        {
            int l=LCA(r,v[i]);
            f[i+1]=tmp+query(in[v[i]])-2*query(in[l])+flag[l]-1;
            //printf("%d: %d %d\n",v[i],f[i+1],l);
        }
        for(int id : v)
        {
            update(in[id],-1),update(out[id]+1,1);
            flag[id]=0;
        }
        sort(f+1,f+k+1);
        bool ff=0;
        for(int i=1;i<=k;i++)
            if(f[i]>=m){ff=1;break ;}
        if(ff){puts("0");continue ;}
        for(int j=0;j<=m;j++)dp[j]=0;
        dp[0]=1;
        for(int i=1;i<=k;i++)
        {
            for(int j=min(i,m);j>=0;j--)
            {
                if(j<=f[i])dp[j]=0;
                else
                {
                    dp[j]=1ll*dp[j]*(j-f[i])%mod;
                    add(dp[j],dp[j-1]);
                }
            }
        }
        ll ans=0;
        for(int j=1;j<=m;j++)add(ans,dp[j]);
        printf("%lld\n",ans);
    }
    return 0;
}
