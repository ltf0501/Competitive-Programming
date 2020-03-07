#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
ll a[maxn],c[maxn];
int n,r[maxn];
void add(int x,ll d)
{
    for(int i=x;i<=n;i+=i&-i)
        c[i]+=d;
}
int query(int x)
{
    ll ret=0;
    for(int i=x;i;i-=i&-i)
        ret+=c[i];
    return ret;
}
bool cmp(int x,int y){return a[x]>a[y] || (a[x]==a[y] && x>y);}
main()
{
    int cas=0;
    while(~scanf("%d",&n) && n)
    {
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++)r[i]=i;
        sort(r+1,r+n+1,cmp);
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=query(r[i]);
            add(r[i],1);
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
