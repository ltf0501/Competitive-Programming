#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=1e16;
#define maxn 1000010
bool vis[maxn];
int n,m,k;
int a[maxn],pre[maxn];
int gao(int len)
{
    int ret=0;
    int r=0,now=-1;
    while(r<n)
    {
        if(pre[r]<=now)return -1;
        now=pre[r];
        r=pre[r]+len;
        ret++;
    }
    return ret;
}
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int x;scanf("%d",&x);
        vis[x]=1;
    }
    for(int i=1;i<=k;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])pre[i]=i;
        else if(i)pre[i]=pre[i-1];
        else pre[i]=-1;
    }
    ll ans=INF;
    for(int i=1;i<=k;i++)
    {
        int tmp=gao(i);
        if(tmp!=-1)ans=min(ans,1ll*tmp*a[i]);
    }
    printf("%lld\n",ans==INF ? -1 : ans);
    return 0;
}
