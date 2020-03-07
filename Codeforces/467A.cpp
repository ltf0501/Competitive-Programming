#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(y-x>=2)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
