#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+5
int a[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    bool flag=0;
    for(int i=1;i<=n-2;i++)
        if(a[i]+a[i+1]>a[i+2]){flag=1;break;}
    if(flag)puts("YES");
    else puts("NO");
    return 0;
}

