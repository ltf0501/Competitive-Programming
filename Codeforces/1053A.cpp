#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
main()
{
    scanf("%d%d%d",&n,&m,&k);
    int a=n,b=m;
    int g=__gcd(n,k);
    n/=g,k/=g;
    g=__gcd(m,k);
    m/=g,k/=g;
    if(k>2)return 0*puts("NO");
    puts("YES");
    if(k==1)
    {
        if(a!=n)n*=2;
        else m*=2;
    }
    printf("0 0\n%d 0\n0 %d\n",n,m);
    return 0;
}

