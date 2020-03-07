#include<bits/stdc++.h>
using namespace std;

main()
{
    int m,n;
    while(~scanf("%d%d",&m,&n) && m+n)
    {
        if(m==1)
        {
            if(n==1)puts("0/1");
            else puts("1/0");
            continue;
        }
        int lp=0,lq=1,rp=1,rq=0;
        int nn=1<<(m-2);
        while(nn>1)
        {
            nn>>=1;
            if(n<=nn)rp+=lp,rq+=lq;
            else lp+=rp,lq+=rq,n-=nn;
        }
        printf("%d/%d\n",lp+rp,lq+rq);
    }
    return 0;
}
