#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,k;scanf("%d%d",&n,&k);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        ans+=2*min(x,k-x);
    }
    printf("%d\n",ans);
    return 0;
}
