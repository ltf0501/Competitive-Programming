#include<bits/stdc++.h>
using namespace std;

main()
{
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    bool flag=0;
    if((a&&b)==c)puts("AND"),flag=1;
    if((a||b)==c)puts("OR"),flag=1;
    if(((a && !b) || (!a && b))==c)puts("XOR"),flag=1;
    if(!flag)puts("IMPOSSIBLE");
    return 0;
}
