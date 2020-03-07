#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    int now=6;
    while(n--)
    {
        int x;scanf("%d",&x);
        if(((1<<x)&now)==0){puts("NO");return 0;}
        now=14-now+(1<<x);
        //printf("%d\n",now);
    }
    puts("YES");
    return 0;
}

