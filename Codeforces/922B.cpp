#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int k=i^j;
            if(j<=k && k<=n && i+j>k)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

