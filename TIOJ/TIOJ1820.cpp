#include<bits/stdc++.h>
#include "lib1820.h"
using namespace std;
int n,a;
int check(int n)
{
    if(n&1)return 0;
    int cnt=0;
    while(!(n&1))n/=2,cnt++;
    if(n>1)return n;
    if(cnt&1)return 0;
    return -1;
}
main()
{
    //while(cin>>n)printf("%d\n",check(n));
    n=initial();
    if(!check(n))
    {
        n-=first(false);
        while(1)
        {
            int a=check(n);
            if(a==-1)
            {
                int k=n/2;
                n/=2;
                n-=play_with_loli(k);
            }
            else n-=a,n-=play_with_loli(a);
        }
    }
    else
    {
        first(true);
        while(1)
        {
            int a=check(n);
            if(a==-1)
            {
                int k=n/2;
                n/=2;
                n-=play_with_loli(k);
            }
            else n-=a,n-=play_with_loli(a);
        }
    }

    return 0;
}
