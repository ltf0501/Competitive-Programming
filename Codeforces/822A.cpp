#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int a,b;scanf("%d%d",&a,&b);
    int k=min(a,b);
    ll ans=1;
    for(int i=1;i<=k;i++)ans*=i;
    printf("%I64d\n",ans);
    return 0;
}

