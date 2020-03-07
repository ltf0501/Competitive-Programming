#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    if(n>36)return 0*puts("-1");
    if(!n)return 0*puts("1");
    while(n>=2)putchar('8'),n-=2;
    return n ? 0*putchar('9') : 0;
    return 0;
}

