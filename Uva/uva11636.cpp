#include<cstdio>
using namespace std;

int ans(int n)
{
    if(n==1)return 0;
    int s=1,need;
    for(int i=1;;i++)
    {
       s*=2;
       if(n<=s){need=i;break;}
    }
    return need;
}
main()
{
    int n,kase=0;
    while(scanf("%d",&n)==1&&n>0)
    {
       printf("Case %d: %d\n",++kase,ans(n));

    }
    return 0;
}
