#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
ll a[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]+=a[i-1];
    if(a[n]<=m){puts("GGGGGZ");return 0;}
    int ans=n;
    int l=1,r=1;
    ll sum;
    while(r<=n)
    {
        sum=a[r]-a[l-1];
        if(sum>=m){ans=min(ans,r-l+1);l++;}
        else r++;
    }
    printf("%d\n",ans);
    return 0;
}
