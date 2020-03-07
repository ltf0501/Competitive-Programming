#include<bits/stdc++.h>
using namespace std;
main()
{
    int x,y;scanf("%d%d",&x,&y);
    if(y<2 && x)return 0*puts("No");
    x-=y-1;
    if(x%2==0 && x>=0)puts("Yes");
    else puts("No");
    return 0;
}

