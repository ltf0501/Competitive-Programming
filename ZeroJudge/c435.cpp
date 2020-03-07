#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
#define INF 100000000
main()
{
    int ans=-INF;
    int n;scanf("%d",&n);
    int pre_max;scanf("%d",&pre_max);
    for(int i=2;i<=n;i++)
    {
        int x;scanf("%d",&x);
        ans=max(ans,pre_max-x);
        pre_max=max(pre_max,x);
    }
    printf("%d\n",ans);
    return 0;
}
