#include<bits/stdc++.h>
using namespace std;
#define maxn 10010
int a[maxn],b[maxn];
main()
{
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    while(m--)
    {
        for(int i=1;i<=n;i++)b[i]=a[i];
        int l,r,x;scanf("%d%d%d",&l,&r,&x);
        sort(b+l,b+r+1);
        if(b[x]==a[x])puts("Yes");
        else puts("No");
    }
    return 0;
}
