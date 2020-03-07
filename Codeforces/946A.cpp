#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        ans+=abs(x);
    }
    printf("%d\n",ans);
    return 0;
}
