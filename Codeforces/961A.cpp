#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int a[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x;scanf("%d",&x);
        a[x]++;
    }
    int ans=1001;
    for(int i=1;i<=n;i++)
        ans=min(ans,a[i]);
    printf("%d\n",ans);
    return 0;
}

