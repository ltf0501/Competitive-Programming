#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
int x,y;
vector<int> v;
ll dp[2005];
ll mypow(ll a,ll n)
{
    ll ret=1;
    while(n)
    {
        if(n&1)ret=ret*a%mod;
        n>>=1;
        a=a*a%mod;
    }
    return ret;
}
main()
{
    scanf("%d%d",&x,&y);
    if(y%x){puts("0");return 0;}
    y/=x;
    for(int i=1;i*i<=y;i++)
    {
        if(y%i==0 && i*i!=y)v.push_back(i),v.push_back(y/i);
        if(i*i==y)v.push_back(i);
    }

    sort(v.begin(),v.end());
    int N=v.size();
    ///printf("%d\n",N);
    ///for(int s : v)printf("%d ",s);puts("");
    for(int i=N-1;i>=0;i--)
    {
        dp[i]=mypow(2,(ll)y/v[i]-1);
        ///printf("%d ",y/v[i]-1);
        for(int j=i+1;j<N;j++)if(v[j]%v[i]==0)dp[i]=(dp[i]-dp[j]+mod)%mod;
        ///printf("%I64d\n",dp[i]);
    }
    ///puts("XD");
    printf("%I64d\n",dp[0]);
    return 0;
}
