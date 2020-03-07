#include<bits/stdc++.h>
using namespace std;
int a[105];
main()
{
    int n,d;scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans=105;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
            if(a[j]-a[i]<=d)ans=min(ans,n-j+i-1);
    }
    printf("%d\n",ans);
    return 0;
}

