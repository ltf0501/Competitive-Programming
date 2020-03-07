#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
const int mod=1e9+7;
struct BIT
{
    int n;
    ll bit[maxn];
    void init(int n)
    {
        this->n=n;
        memset(bit,0,sizeof(bit));
    }
    void add(int x,ll d)
    {
        for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
    }
    ll query(int x)
    {
        ll ret=0;
        for(int i=x;i;i-=i&-i)ret+=bit[i];
        return ret;
    }
    ll query(int x,int y){return query(y)-query(x-1);}
}b1,b2;
int n,q;
int a[maxn],w[maxn];
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]-=i;
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    b1.init(n),b2.init(n);
    for(int i=1;i<=n;i++)b1.add(i,w[i]);
    for(int i=1;i<=n;i++)b2.add(i,1ll*a[i]*w[i]%mod);
    while(q--)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(x<0)
        {
            x=-x;
            ll tmp1=y-w[x],tmp2=1ll*a[x]*tmp1%mod;
            b1.add(x,tmp1),b2.add(x,tmp2);
            w[x]=y;
        }
        else
        {
            ll sum=b1.query(x,y);
            int l=x,r=y;
            while(r-l>=1)
            {
                int m=(l+r)>>1;
                if(b1.query(x,m)*2>=sum)r=m;
                else l=m+1;
            }
            int k=l;
            ll ans=0;
            (ans+=(a[k]*(b1.query(x,k-1)%mod)%mod-b2.query(x,k-1)))%=mod;
            (ans+=(b2.query(k+1,y)-a[k]*(b1.query(k+1,y)%mod)%mod))%=mod;
            if(ans<0)ans+=mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
