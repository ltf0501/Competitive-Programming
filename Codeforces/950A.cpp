#include<bits/stdc++.h>
using namespace std;

main()
{
    int l,r,a;scanf("%d%d%d",&l,&r,&a);
    int ans=min(l,r);
    l-=ans,r-=ans;
    ans*=2;
    int t=max(l,r);
    ans+=2*min(t,a);
    if(a>t)ans+=((a-t)/2)*2;
    printf("%d\n",ans);
    return 0;
}

