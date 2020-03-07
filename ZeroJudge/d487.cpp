#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
    if(n==0)return 1;
    return n*f(n-1);
}
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0){puts("0! = 1 = 1");continue;}
        printf("%d! = ",n);
        for(int i=n;i>=2;i--)printf("%d * ",i);
        printf("1 = %d\n",f(n));
    }
    return 0;
}
