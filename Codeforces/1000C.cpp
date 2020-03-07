#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200010
#define pli pair<ll,int>
#define F first
#define S second
pli a[maxn<<1];
int n;
ll cnt[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        ll l,r;scanf("%lld%lld",&l,&r);
        a[2*i-1]=pli(l,1),a[2*i]=pli(r+1,-1);
    }
    sort(a+1,a+2*n+1);
    int cur=0;
    for(int i=1;i<=2*n;i++)
    {
        cnt[cur]+=a[i].F-a[i-1].F;
        cur+=a[i].S;
    }
    for(int i=1;i<=n;i++)printf("%lld ",cnt[i]);
    return 0;
}

