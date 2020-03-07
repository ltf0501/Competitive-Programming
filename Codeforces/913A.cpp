#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,m;scanf("%d%d",&n,&m);
    if(n>=27)printf("%d\n",m);
    else printf("%d\n",m%(1<<n));
    return 0;
}

