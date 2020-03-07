#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100100
ll a[maxn];
main()
{
    ll n;int k;scanf("%I64d%d",&n,&k);
    int cnt=0;
    for(int i=0;i<64;i++)
        if((1ll<<i)&n)cnt++,a[i+100000]=1;
    if(cnt>k)return 0*puts("No");
    //printf("%d\n",cnt);
    puts("Yes");
    for(int i=100000+63;;i--)
    {
        if(cnt+a[i]<k)cnt+=a[i],a[i-1]+=2*a[i],a[i]=0;
        else
        {
            a[i]-=(k-cnt),a[i-1]+=2*(k-cnt);
            break;
        }
    }
    for(int i=100000+64;i>=0;i--)
        while(a[i]--)printf("%d ",i-100000);
    return 0;
}
