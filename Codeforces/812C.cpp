#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n;
ll s,ans=0;
ll a[maxn];
ll t[maxn];
bool check(int k)//對個數二分
{
    for(int i=1;i<=n;i++)t[i]=a[i]+(ll)i*k;
    sort(t+1,t+n+1);
    ll sum=0;
    for(int i=1;i<=k;i++)
    {
        sum+=t[i];
        if(sum>s)return 0;
    }
    ans=sum;
    return 1;
}
main()
{
    scanf("%d%I64d",&n,&s);
    for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
    int l=0,r=n+1;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(check(mid))l=mid;
        else r=mid;
    }
    printf("%d %I64d\n",l,ans);
    return 0;
}
