#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define maxn 1000010
#define ll long long
int n,k;
int a[maxn],pre[maxn],suf[maxn];
deque<int> dq;
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=a[n+1]=mod;
    dq.push_back(0);
    for(int i=1;i<=n;i++)
    {
        while(a[i]>a[dq.back()])dq.pop_back();
        pre[i]=dq.back()+1;
        dq.push_back(i);
    }
    dq.clear();
    dq.push_back(n+1),suf[n+1]=n+1;
    for(int i=n;i>=1;i--)
    {
        while(a[i]>a[dq.back()])dq.pop_back();
        suf[i]=dq.back()-1;
        dq.push_back(i);
    }
    for(int i=1;i<=n;i++)printf("%d ",pre[i]);puts("");
    for(int i=1;i<=n;i++)printf("%d ",suf[i]);puts("");
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ll cnt=0;
        int x=i-pre[i],y=suf[i]-i;
        int s=min(x,y);
        int p=s/k;int q=(x+y)/k-p;
        cnt=1ll*(p+q)*s%mod;
        printf("%d: %d\n",i,cnt);
        ans=(ans+1ll*cnt*a[i])%mod;
    }
    printf("%lld\n",ans);
    return 0;
}
