#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int sol(int a,int b)
{
    if(a*b==0)return 0;
    return a/b+sol(b,a%b);
}
main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        if(a<b)swap(a,b);
        printf("%d\n",sol(a,b));
    }
    return 0;
}
