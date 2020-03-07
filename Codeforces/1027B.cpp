#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int n,q;scanf("%d%d",&n,&q);
    while(q--)
    {
        int x,y;scanf("%d%d",&x,&y);
        ll ans;
        if((x+y)%2==0)
        {
            ans=1ll*((x-1)/2)*n+(x%2==0 ? (n+1)/2 : 0)+(y+1)/2;
        }
        else
        {
            ans=(1ll*n*n+1)/2+1ll*((x-1)/2)*n+(x%2==0 ? n/2 : 0)+(y+1)/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
