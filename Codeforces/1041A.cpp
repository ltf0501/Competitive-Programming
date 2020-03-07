#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
int n,a[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    printf("%d\n",a[n]-a[1]+1-n);
    return 0;
}

