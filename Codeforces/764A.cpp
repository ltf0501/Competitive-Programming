#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int gcd(int a,int b)
{
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}
main()
{
    int n,m,z;
    scanf("%d%d%d",&n,&m,&z);
    int t=gcd(n,m);
    int ans=n*m/t;
    printf("%d\n",z/ans);
    return 0;
}
