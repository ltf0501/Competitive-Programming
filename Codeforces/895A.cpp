#include<bits/stdc++.h>
using namespace std;
#define maxn 365
int a[maxn],s[maxn];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
    if(n==1)
    {
        puts("360");
        return 0;
    }
    int ans=360;
    for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)
        ans=min(ans,2*abs(s[j]-s[i-1]-180));
    printf("%d\n",ans);
    return 0;
}

