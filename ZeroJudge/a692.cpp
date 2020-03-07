#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000010
int n,k,a[maxn],cnt;
vector<int> g[maxn];
ll sz[maxn],m;
void dfs(int u,int fa)
{
    sz[u]=a[u];
    for(int v : g[u])if(v!=fa)
    {
        dfs(v,u);
        sz[u]+=sz[v];
    }
    if(sz[u]>=m)sz[u]=0,cnt++;
}
bool check()
{
    cnt=0;
    memset(sz,0,sizeof(sz));
    dfs(1,-1);
   // printf("%lld %d\n",m,cnt);
    return cnt>=k;
}
main()
{
    scanf("%d%d",&n,&k);
    ll mx=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx+=a[i];
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].push_back(y),g[y].push_back(x);
    }
    ll l=1,r=mx/k,ans=1;
    while(l<=r)
    {
        m=(l+r)/2;
        if(check())l=m+1,ans=m;
        else r=m-1;
        //printf("l,r = %lld %lld\n",l,r);
    }
    printf("%lld\n",ans);
    return 0;
}
