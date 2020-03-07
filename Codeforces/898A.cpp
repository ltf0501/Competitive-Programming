#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    int k=n/10;
    if(n-10*k<10*(k+1)-n)printf("%d\n",10*k);
    else printf("%d\n",10*(k+1));
    return 0;
}
