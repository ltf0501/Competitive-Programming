#include<bits/stdc++.h>
using namespace std;
int n;
main()
{
    int ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int l,r;scanf("%d%d",&l,&r);
        ans+=(r-l+1);
    }
    printf("%d\n",ans);
    return 0;
}

