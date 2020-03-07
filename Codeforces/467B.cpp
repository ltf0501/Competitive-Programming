#include<bits/stdc++.h>
using namespace std;
#define maxm 1005
int a[maxm];
main()
{
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m+1;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)if( (a[i]&(1<<j))^(a[m+1]&(1<<j)) )cnt++;
        if(cnt<=k)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
