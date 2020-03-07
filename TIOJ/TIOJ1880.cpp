#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+5
#define mod 1000007
#define ll long long
int col[maxn];
vector<int> g[maxn];
bool dfs(int u,int c)
{
    col[u]=c;
    for(auto v : g[u])
    {
        if(col[v]==c)return 0;
        if(!col[v])
            if(!dfs(v,3-c))return 0;
    }
    return 1;
}
ll pow(int a,int k)
{
    if(k==0)return 1;
    ll ans=pow(a,k/2);
    ans=(ans*ans)%mod;
    if(k&1)ans=(ans*a)%mod;
    return ans;
}
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)if(!col[i])
    {
        if(!dfs(i,1)){puts("0");return 0;}
        cnt++;
    }
    ll ans=pow(2,cnt-1);
    printf("%lld\n",ans);
    return 0;
}
