#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
/*
int phi(int n)
{
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)res=res*(i-1)/i;
        while(n%i==0)n/=i;
    }
}
*/
int q(int n)
{
    int res=0;
    while(n)
    {
        res+=n%10;
        n/=10;
    }
    return res;
}
main()
{
    int k;scanf("%d",&k);
    while(k%2==0)k/=2;
    while(k%5==0)k/=5;
    int ans=100;
    for(int i=1;i<=9;i++)ans=min(ans,q(i*k));
    printf("%d\n",ans);
    return 0;
}
