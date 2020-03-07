#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,m;
int x[maxn];
int cnt[maxn];
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    x[++n]=(int)1e9;
    sort(x+1,x+n+1);
    for(int i=1;i<=m;i++)
    {
        int x1,x2,y;scanf("%d%d%d",&x1,&x2,&y);
        if(x1!=1)continue;
        int k=upper_bound(x+1,x+n+1,x2)-x;
        cnt[--k]++;
    }
    for(int i=n;i>=1;i--)cnt[i]+=cnt[i+1];
    int ans=1e9;
    for(int i=1;i<=n;i++)ans=min(ans,i-1+cnt[i]);
    printf("%d\n",ans);
    return 0;
}
