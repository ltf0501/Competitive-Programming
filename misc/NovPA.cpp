#include<bits/stdc++.h>
using namespace std;

main()
{
    int a,b;scanf("%d%d",&a,&b);
    if(a%b==0)printf("%d\n",a/b);
    else printf("%d\n",a/b+1);
    return 0;
}

