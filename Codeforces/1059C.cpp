#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int n;
main()
{
    scanf("%d",&n);
    if(n<=3)
    {
        if(n==1)puts("1");
        else if(n==2)puts("1 2");
        else puts("1 1 3");
        return 0;
    }
    int k=n;
    int cur=1;
    while(cur<=n)
    {
        if(k==3){printf("%d %d %d\n",cur,cur,3*cur);return 0;}
        int num=(k+1)/2;
        //printf("num = %d\n",num);
        for(int i=1;i<=num;i++)printf("%d ",cur);
        k-=num;
        cur<<=1;
    }
    //printf("%d\n",k);
    return 0;
}
