#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,k;scanf("%d%d",&n,&k);
    printf("%d\n",n-1+n+1+n+min(k-1,n-k));
    return 0;
}
