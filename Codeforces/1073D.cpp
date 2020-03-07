#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int n,nxt[maxn];
ll k;
ll bit[maxn],a[maxn];
void add(int x,ll d)
{
    if(!x)return ;
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
ll query(int x)
{
    ll ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
main()
{
    scanf("%d%lld",&n,&k);
    ll sum=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
    for(int i=1;i<=n;i++)
    {
        bit[i]+=a[i],bit[i+(i&-i)]+=bit[i];
    }
    for(int i=0;i<n;i++)nxt[i]=i+1;
    ll ans=0;
    if(k>=sum)ans+=k/sum*n,k%=sum;
    for(int i=1;i<=n-1 && k>0;i++)
    {
        int now=0;
        for(int j=17;j>=0;j--)if(now+(1<<j)<=n)
        {
            now+=(1<<j);
            if(query(now)>k)now-=(1<<j);
        }
        ll tot=query(n)-a[nxt[now]];
        ll tt=(k/tot)*(n-i);
        ans+=tt;
        if(tot)k%=tot;
        add(nxt[now],-a[nxt[now]]);
        nxt[now]=nxt[nxt[now]];
    }
    ans+=k/query(n);
    printf("%lld\n",ans);
    return 0;
}
