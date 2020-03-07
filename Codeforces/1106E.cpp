#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
const ll INF=1e16;
multiset<pii> s;
int n,m,k;
struct Q
{
    int d,w,flag;
};
vector<Q> v[maxn];
ll dp[2][maxn];
int nxt[maxn],w[maxn];
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        int l,r,d,w;scanf("%d%d%d%d",&l,&r,&d,&w);
        v[l].push_back({d,w,1}),v[r+1].push_back({d,w,-1});
    }
    for(int i=1;i<=n;i++)nxt[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(Q tmp : v[i])
        {
            if(tmp.flag==1)s.insert(pii(-tmp.w,-tmp.d));
            else s.erase(s.find(pii(-tmp.w,-tmp.d)));
        }
        if(!s.empty())
        {
            auto it=s.begin();
            w[i]=-(it->F),nxt[i]=-(it->S);
        }
    }
    for(int i=1;i<=n;i++)printf("%d %d\n",w[i],nxt[i]);
    for(int i=1;i<=n;i++)dp[0][i]=dp[1][i]=INF;
    dp[0][1]=0;
    ll ans=INF;
    for(int j=0;j<=m;j++)
    {
        for(int i=0;i<=n+1;i++)dp[(j&1)^1][i]=INF;
        for(int i=1;i<=n;i++)
        {
            dp[(j&1)^1][i+1]=min(dp[(j&1)^1][i+1],dp[j&1][i]);
            dp[j&1][nxt[i]+1]=min(dp[j&1][nxt[i]+1],dp[j&1][i]+w[i]);
        }
        ans=min(ans,dp[j&1][n+1]);
        for(int i=1;i<=n+1;i++)printf("%lld ",dp[j&1][i]);
    }
    printf("%lld\n",ans);

    return 0;
}
