#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[11][70][1100];
void pre()
{
    for(int b=2;b<=10;b++)
    {
        dp[b][0][0]=1;
        for(int len=1;len<=63;len++)
            for(int t=0;t<(1<<b);t++)
                for(int d=0;d<b;d++)dp[b][len][t]+=dp[b][len-1][t^(1<<d)];
    }
}
ll sol(int b,ll n)
{
    vector<int> a;
    while(n)
    {
        a.push_back(n%b);
        n/=b;
    }
    int h=a.size();
    ll ret=0;
    for(int i=1;i<h;i++)ret+=dp[b][i][0]-dp[b][i-1][1];
    int cur=0;
    for(int i=h-1;i>=0;i--)
    {
        for(int j=0;j<a[i];j++)
        {
            if(i==h-1 && !j)continue;
            ret+=dp[b][i][cur^(1<<j)];
        }
        cur^=(1<<a[i]);
    }
    return ret;
}
main()
{
    pre();
    int q;scanf("%d",&q);
    while(q--)
    {
        int b;scanf("%d",&b);
        ll l,r;scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",sol(b,r+1)-sol(b,l));
    }
    return 0;
}
