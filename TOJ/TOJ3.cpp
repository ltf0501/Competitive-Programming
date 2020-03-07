#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int a,b;scanf("%d%d",&a,&b);
        int ans=gcd(a,b);
        printf("%d\n",ans);
    }
    return 0;
}
