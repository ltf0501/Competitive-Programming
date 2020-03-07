#include <cstdio>
#include <algorithm>
#include<cstring>
using namespace std;

long long c(int k)
{
    if(k==0) return 1;
    else return 3*c(k-1);
}
long long int dp(int k,int i)
{
    if(i==0)return 0;
    if(k==0)return 1;
    if(i>=(1<<(k-1))) return 2*dp(k-1,i-(1<<(k-1)))+c(k-1);
    else return dp(k-1,i);
}
main()
{
    int t,k,a,b;
    scanf("%d",&t);
    int i=0;
    while(t--)
    {
        scanf("%d %d %d",&k,&a,&b);
        int x=(1<<k)-a+1,y=(1<<k)-b;
        printf("Case %d: %lld\n",++i,dp(k,x)-dp(k,y));
    }
    return 0;
}

