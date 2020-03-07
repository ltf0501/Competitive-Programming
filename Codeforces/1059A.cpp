#include<bits/stdc++.h>
using namespace std;
int n,L,a;
#define maxn 100010
int t[maxn],l[maxn];
main()
{
    scanf("%d%d%d",&n,&L,&a);
    for(int i=1;i<=n;i++)scanf("%d%d",&t[i],&l[i]);
    t[n+1]=L;
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        ans+=(t[i+1]-t[i]-l[i])/a;
        //printf("%d\n",t[i+1]-t[i]-l[i]);
    }
    printf("%d\n",ans);
    return 0;
}

