#include<bits/stdc++.h>
using namespace std;

main()
{
    int a,b;scanf("%d%d",&a,&b);
    int x=sqrt(a+0.5);
    int y=sqrt(b-0.5);
    if(x<=y)puts("Vladik");
    else puts("Valera");
    return 0;
}

