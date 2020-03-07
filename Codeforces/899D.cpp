#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
bool check(int n)
{
    while(n)
    {
        if(n%10 && n!=1)return 0;
        n/=10;
    }
    return 1;
}
int pw(int n)
{
    int ret=1;
    while(n)n--,ret*=10;
    return ret;
}
main()
{
    scanf("%I64d",&n);
    int k=2*n-1;
    if(check(k+1)){puts("1");return 0;}
    int tk=k;
    int num=0,pre=0;
    while(tk)tk/=10,num++;
    num--;
    int s=pw(num);
    //printf("%d\n",s);
    for(int i=1;;i++)
    {
        if((i+1)*s-1>k){pre=i-1;break;}
    }
    //printf("%d %d\n",pre,num);
    int ans=0;
    for(int i=0;i<=pre;i++)
    {
        int tmp=(i+1)*s-1;
        //printf("%d\n",tmp);
        int mx=min(n,tmp-1);
        int mi=max(1ll,tmp-mx);
        ans+=(mx-mi+1)/2;
    }
    printf("%I64d\n",ans);
    return 0;
}
