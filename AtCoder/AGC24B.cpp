#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int n,a[maxn],pos[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
    int mx=0,now=1;
    for(int i=2;i<=n+1;i++)
    {
        if(pos[i]>pos[i-1])now++;
        else
        {
            mx=max(mx,now);
            now=1;
        }
    }
    printf("%d\n",n-mx);
    return 0;
}
