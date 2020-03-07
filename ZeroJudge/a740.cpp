#include<bits/stdc++.h>
using namespace std;

int gao(int n)
{
    int tmp=n;
    int ret=0;
    for(int i=2;i*i<=n;i++)if(tmp%i==0)
    {
        while(tmp%i==0)ret+=i,tmp/=i;
    }
    if(tmp!=1)ret+=tmp;
    return ret;
}
main()
{
    int n;
    while(~scanf("%d",&n))printf("%d\n",gao(n));
    return 0;
}
