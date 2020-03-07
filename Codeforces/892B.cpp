#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int a[maxn];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int ans=n,l=n;
    for(int i=n;i>=1;i--)
    {
        if(i-a[i]>=l || !a[i])continue;
        l=min(l,i);
        ans-=l-max(1,(i-a[i]));
        l=max(1,(i-a[i]));
        //printf("%d %d %d\n",i,ans,l);
    }
    printf("%d\n",ans);
    return 0;
}
/*
10
1 1 3 0 0 0 2 1 0 3

4
0 1 0 10
*/
