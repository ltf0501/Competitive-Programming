#include<bits/stdc++.h>
using namespace std;
int Pow(long long x, int n, long long mod)
{
    long long Ans=1,t=x;
    while(n)
    {
        if(n&1)
            Ans*=t,Ans%=mod;
        t*=t,t%=mod,n>>=1;
    }
    return (int)Ans;
}
int JudgePrime(int n)
{
    if(n==2 || n==3)return 1;
    int b[3]={2,1215,34682};
    if(n==1)return 0;
    if(!(n&1))return 0;
    int x,t;
    for(int i=0;i<3;a++)
    {
        x=b[i];
        t=Pow(x,n-1,n);
        if(t!=1)return 0;
    }
    return 1;
}
main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        if(JudgePrime(n))puts("0");
        else puts("1");
    }
    return 0;
}
