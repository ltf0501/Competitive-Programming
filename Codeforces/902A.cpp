#include<bits/stdc++.h>
using namespace std;
int n,m;
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        if(now<a){puts("NO");return 0;}
        now=max(now,b);
    }
    if(now==m)puts("YES");
    else puts("NO");
    return 0;
}

