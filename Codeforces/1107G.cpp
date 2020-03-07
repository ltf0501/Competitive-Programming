#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300010
int d[maxn];
ll a[maxn];
vector<pair<ll,int> > v;
int p[maxn];
ll pre[maxn],suf[maxn],sum[maxn],res[maxn];
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void Union(int x,int y)
{
    x=finds(x),y=finds(y);
    if(x==y)return ;
    p[y]=x;
    res[x]=max({res[x],res[y],suf[x]+pre[y]});
    pre[x]=max(pre[x],sum[x]+pre[y]);
    suf[x]=max(suf[y],suf[x]+sum[y]);
    sum[x]+=sum[y];
}
main()
{
    int n,k;scanf("%d%d",&n,&k);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%lld",&d[i],&a[i]);
        a[i]=k-a[i];
        pre[i]=suf[i]=res[i]=max(0ll,a[i]);
        sum[i]=a[i];
        p[i]=i;
        ans=max(ans,a[i]);
        if(i==1)continue;
        ll val=1ll*(d[i]-d[i-1])*(d[i]-d[i-1]);
        v.push_back({val,i});
    }
    sort(v.begin(),v.end());
    for(auto s : v)
    {
        ll val=s.first;
        int id=s.second;
        //printf("%d ",id);
        Union(id-1,id);
        int ii=finds(id);
        ans=max(ans,res[ii]-val);
        //printf("%d: %lld %lld\n",ii,res[ii]-val,val);
    }
    printf("%lld\n",ans);
    return 0;
}
