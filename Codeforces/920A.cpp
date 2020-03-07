#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[205];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k;i++)scanf("%d",&a[i]);
        a[k+1]=100000;
        a[0]=-100000;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int s=upper_bound(a+1,a+k+1,i)-a-1;
            //printf("%d ",a[s]);
            ans=max(ans,min(i-a[s],a[s+1]-i)+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}
