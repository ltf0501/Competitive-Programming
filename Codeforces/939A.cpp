#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
int n,a[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(a[a[a[i]]]==i)return 0*puts("YES");
    return 0*puts("NO");
    return 0;
}
