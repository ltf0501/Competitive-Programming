#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
#define ll long long
ll a[maxn],b[maxn],s[maxn],t[maxn];
int n,k1,k2;
main()
{
    scanf("%d%d%d",&n,&k1,&k2);
    int k=k1+k2;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++)s[i]=abs(a[i]-b[i]);
    sort(s+1,s+n+1,greater<int>());
    if(!k)
    {
        ll ans=0;
        for(int i=1;i<=n;i++)ans+=s[i]*s[i];
        printf("%lld\n",ans);
        return 0;
    }
    //for(int i=1;i<=n+1;i++)printf("%lld ",s[i]);puts("");
    for(int i=2;i<=n+1;i++)t[i]=t[i-1]+(i-1)*(s[i-1]-s[i]);
    //for(int i=1;i<=n+1;i++)printf("%lld ",t[i]);puts("");
    if(t[n+1]<=k)
    {
        if((t[n+1]+k)%2==0)return 0*puts("0");
        return 0*puts("1");
    }
    int m=lower_bound(t+1,t+n+1,k)-t;
    //printf("%d\n",m);
    m--;
    k-=t[m];
    ll ans=0;
    for(int i=n;i>m;i--)ans+=s[i]*s[i];
    int x=k/m,y=k%m;
    //printf("%d %d\n",x,y);
    ans+=y*(s[m]-x-1)*(s[m]-x-1)+(m-y)*(s[m]-x)*(s[m]-x);
    printf("%lld\n",ans);
    return 0;
}
