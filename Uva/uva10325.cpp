#include <iostream>
#include <cstdio>
using namespace std;
#define LL long long
LL gcd(LL a,LL b)
{
    return b==0 ? a : gcd(b,a%b);
}

LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}
LL N,M,sel[16];
main()
{
    while(scanf("%lld%lld",&N,&M)==2)
    {
        LL ans=N;
        LL uni=0;
        for(int i=0;i<M;i++)scanf("%lld",&sel[i]);

        for(LL i=0;i<(1<<M);i++)
        {
            LL cnt=0,lcmn=1;
            for(LL j=0;j<M;j++)
            {
                if((1<<j)&i)
                {
                    cnt++;
                    lcmn=lcm(lcmn,sel[j]);
                }
            }
            if(cnt==0)continue;
            if(cnt&1)uni+=N/lcmn;
            else uni -= N / lcmn;
        }

        printf("%lld\n",ans-uni);
    }
    return 0;
}
