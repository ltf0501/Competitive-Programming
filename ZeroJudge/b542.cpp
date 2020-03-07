#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
ll c[maxn],t[maxn];
int n,q;
bool check(ll k)
{
    int l=0,r=0;
    ll sum=0;
    if(!k)
    {
        for(int i=1;i<n;i++)
            if(!t[i])return 1;
        return 0;
    }
    while(r<=n-1)
    {
        if(sum==k)return 1;
        if(sum<k)
        {
            if(r<n-1)sum+=t[++r];
            else break;
        }
        else sum-=t[++l];
    }
    return 0;
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%lld",&c[i]);
    sort(c+1,c+n+1);
    for(int i=1;i<n;i++)t[i]=c[i+1]-c[i];
    while(q--)
    {
        ll k;scanf("%lld",&k);
        puts(check(k) ? "YES" : "NO");
    }
    return 0;
}
