#include<bits/stdc++.h>
using namespace std;

main()
{
    int a[2],b[2],c[2];
    scanf("%d%d%d%d%d%d",&a[0],&a[1],&b[0],&b[1],&c[0],&c[1]);
    int p=a[1]*b[1]*c[1],q=a[0]*b[0]*c[0];
    if(p>q)puts("Ron");
    else if(!p && !q)
    {
        if((b[1] && !b[0]) || (!a[0] && a[1] && b[1]))puts("Ron");
        else puts("Hermione");
    }
    else puts("Hermione");
    return 0;
}
