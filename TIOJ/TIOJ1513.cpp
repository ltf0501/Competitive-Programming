#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    unsigned int k,t;
    while(~scanf("%d",&n))
    {
        k=0;
        while(n--)
        {
            scanf("%u",&t);
            k^=t;
        }
        printf("%u\n",k);
    }

}

