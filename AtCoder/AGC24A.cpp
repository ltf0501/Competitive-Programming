#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int a,b,c;
    ll k;
    scanf("%d%d%d%lld",&a,&b,&c,&k);
    int ans=a-b;
    if(k%2==1)ans*=-1;
    printf("%d\n",ans);
    return 0;
}

