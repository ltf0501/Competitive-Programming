#include<bits/stdc++.h>
using namespace std;
int c[3];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        c[x]++;
    }
    int ans;
    if(c[1]>=c[2])
    {
        ans=c[2]+(c[1]-c[2])/3;
    }
    else ans=c[1];
    printf("%d\n",ans);
    return 0;
}

