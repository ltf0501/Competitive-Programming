#include<bits/stdc++.h>
using namespace std;
int n;
main()
{
    scanf("%d",&n);
    for(int i=0;;i++)
    {
        int k;
        for(k=2;;k++)if(k*(k-1)/2>n)break;
        k--;
        n-=k*(k-1)/2;
        //printf("%d ",k);
        while(k--)putchar('a'+i);
        if(!n)break;
    }
    return 0;
}
