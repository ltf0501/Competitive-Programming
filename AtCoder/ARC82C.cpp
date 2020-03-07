#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int cnt[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(x>0)cnt[x-1]++;
        cnt[x]++,cnt[x+1]++;
    }
    int ans=0;
    for(int i=0;i<maxn;i++)ans=max(ans,cnt[i]);
    printf("%d\n",ans);
    return 0;
}
