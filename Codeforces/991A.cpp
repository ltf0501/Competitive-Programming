#include<bits/stdc++.h>
using namespace std;

main()
{
    int a,b,c,n;
    scanf("%d%d%d%d",&a,&b,&c,&n);
    int k=a+b-c;
    int ans=n-k;
    if(ans<=0 || c>a || c>b)puts("-1");
    else printf("%d\n",ans);
    return 0;
}

