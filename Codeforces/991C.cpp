#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll num[2];
main()
{
    scanf("%lld",&n);
    ll l=1,r=n;
    while(l<r)
    {
        ll k=(l+r)>>1;
        ll N=n;num[0]=num[1]=0ll;
        //printf("%lld: ",k);
        //int cnt=0;
        bool flag=0;
        while(N)
        {
            flag^=1;
            if(flag)
            {
                if(k<=N)N-=k,num[flag]+=k;
                else num[flag]+=N,N=0;
            }
            else num[flag]+=N/10,N-=N/10;
            //cnt++;
        }
        //printf("%lld %lld\n",num[1],num[0]);
        if(num[1]>=num[0])r=k;
        else l=k+1;
    }
    printf("%lld\n",l);
    return 0;
}
