#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[105];
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int ans=1000;
    for(int i=1;i<=n;i++)if(k%a[i]==0)
    {
        ans=min(ans,k/a[i]);
    }
    printf("%d\n",ans);
    return 0;
}

