#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int x,int y)
{
    if(x<y)swap(x,y);
    if(y==0)return x;
    return gcd(y,x%y);
}
main()
{
    int n;
    int a,b;
    while(scanf("%d",&n)==1)
    {
        int x;
        scanf("%d",&x);
        for(int i=1;i<n;i++)
        {
            int y;
            scanf("%d",&y);
            x=gcd(x,y);
        }
        printf("%d\n",x);
    }
    return 0;
}
