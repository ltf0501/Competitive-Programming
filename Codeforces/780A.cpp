#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
int a[maxn];
main()
{
    int n;scanf("%d",&n);
    int cnt=0,ans=0;
    for(int i=1;i<=2*n;i++)
    {
        int k;scanf("%d",&k);
        cnt+=a[k] ? -1 : 1;
        ans=max(ans,cnt);
        a[k]^=1;
    }
    printf("%d\n",ans);
    return 0;
}
