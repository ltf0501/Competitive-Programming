#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;scanf("%d",&n);
    for(int i=10;i>=1;i--)
    {
        int t=((1<<i)-1)*(1<<(i-1));
        if(t>n)continue;
        if(n%t==0){printf("%d\n",t);return 0;}
    }
    return 0;
}
