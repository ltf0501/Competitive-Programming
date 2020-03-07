#include<bits/stdc++.h>
using namespace std;
int a[105],n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n&1 && a[1]&1 && a[n]&1)return 0*puts("YES");
    puts("NO");
    return 0;
}

