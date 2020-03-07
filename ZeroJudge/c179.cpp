#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int a[maxn];
ll sum;
int n,k;
bool check(ll s)
{
    int cur=0,cnt=0;
    ll sum=0;
    while(cnt<k && cur<=n)
    {
        if(sum+a[cur+1]<=s)sum+=a[++cur];
        else sum=0,cnt++;
    }
    if(cur<n)return 0;
    return 1;
}
main()
{

    while(~scanf("%d%d",&n,&k))
    {
        sum=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
        ll l=1,r=sum;
        while(r-l>=1)
        {
            int m=(l+r)>>1;
            if(check(m))r=m;
            else l=m+1;
        }
        //printf("%d\n",check(4));
        printf("%lld\n",l);
    }
    return 0;
}
