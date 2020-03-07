#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int a[maxn];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[n+1]=1001;
    int ans=0;
    int now=0;
    for(int i=0;i<=n+1;i++)
    {
        if(a[i+1]==a[i]+1)now++;
        else ans=max(ans,now-2),now=1;
    }
    printf("%d\n",ans);
    return 0;
}

