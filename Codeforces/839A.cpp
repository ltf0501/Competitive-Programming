#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[105];
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int sum=0,cnt=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        int t=min(sum,8);
        cnt+=t;
        sum-=t;
        if(cnt>=k){ans=i;break;}
    }
    if(ans)printf("%d\n",ans);
    else puts("-1");
    return 0;
}

