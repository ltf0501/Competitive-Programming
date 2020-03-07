#include<bits/stdc++.h>
using namespace std;
#define ll long long
const double eps=1e-9;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        ll a,b;scanf("%I64d%I64d",&a,&b);
        ll c=a*b;
        ll k=(ll)(pow(c,1/3.0)+eps);
        bool flag=1;
        if(k*k*k!=c)flag=0;
        else if(a%k!=0 || b%k!=0)flag=0;
        puts(flag ? "Yes" : "No");
    }
    return 0;
}

