#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll k,p,cnt=0;
ll c[1000005];
ll t[15];
void pre()
{
    for(int i=1;i<=9;i++)c[cnt+1]=c[cnt]+11,cnt++;
    c[cnt+1]=1001;cnt++;
    for(int i=2;i<=90;i++)
    {
        if(i%10==1)c[cnt+1]=c[cnt]+11;
        else c[cnt+1]=c[cnt]+110;
        cnt++;
    }
    c[cnt+1]=100001;cnt++;
    for(int i=2;i<=900;i++)
    {
        if(i%100==1)c[cnt+1]=c[cnt]+11;
        else if(i%10==1)c[cnt+1]=c[cnt]+110;
        else c[cnt+1]=c[cnt]+1100;
        cnt++;
    }
    c[cnt+1]=10000001;cnt++;
    for(int i=2;i<=9000;i++)
    {
        if(i%1000==1)c[cnt+1]=c[cnt]+11;
        else if(i%100==1)c[cnt+1]=c[cnt]+110;
        else if(i%10==1)c[cnt+1]=c[cnt]+1100;
        else c[cnt+1]=c[cnt]+11000;
        cnt++;
    }
    c[cnt+1]=1000000001;cnt++;
    for(int i=2;i<=90000;i++)
    {
        if(i%10000==1)c[cnt+1]=c[cnt]+11;
        else if(i%1000==1)c[cnt+1]=c[cnt]+110;
        else if(i%100==1)c[cnt+1]=c[cnt]+1100;
        else if(i%10==1)c[cnt+1]=c[cnt]+11000;
        else c[cnt+1]=c[cnt]+110000;
        cnt++;
    }

    c[cnt+1]=100000000001;cnt++;
    for(int i=2;i<=900000;i++)
    {
        if(i%10!=1) c[cnt+1]=c[cnt]+1100000;
        else if(i%100!=1)c[cnt+1]=c[cnt]+110000;
        else if(i%1000!=1)c[cnt+1]=c[cnt]+11000;
        else if(i%10000!=1)c[cnt+1]=c[cnt]+1100;
        else if(i%100000!=1)c[cnt+1]=c[cnt]+110;
        else c[cnt+1]=c[cnt]+11;
        cnt++;
    }

}
main()
{
    pre();
    //printf("%d\n",cnt);
    scanf("%I64d%I64d",&k,&p);
    ll ans=0;
    for(int i=1;i<=k;i++)ans=(ans+c[i])%p;
    /*
    for(int i=1;i<=c;i++)
    {
        tmp=(tmp*t[i-1]+(t[2*i-1]+1)*t[i-1]*45)%p;
        ans=(ans+tmp)%p;
    }
    k-=t[c];
    */


    printf("%I64d\n",ans);
    return 0;
}
