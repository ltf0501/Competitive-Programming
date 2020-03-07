#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,k;
ll s;
main()
{
    scanf("%d%d%lld",&n,&k,&s);
    if(s<k || 1ll*(n-1)*k<s)return 0*puts("NO");
    puts("YES");
    int cur=1;
    while(k)
    {
        ll umr=min(1ll*n-1,s-k+1);
        s-=umr;
        if(cur+umr<=n)cur+=umr;else cur-=umr;
        printf("%d ",cur);
        k--;
    }

    return 0;
}
