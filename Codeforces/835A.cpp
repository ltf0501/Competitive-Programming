#include<bits/stdc++.h>
using namespace std;
int s,v1,v2,t1,t2;
main()
{
    scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
    int a=2*t1+s*v1,b=2*t2+s*v2;
    if(a<b)puts("First");
    else if(a>b)puts("Second");
    else puts("Friendship");
    return 0;
}
