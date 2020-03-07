#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
ll a[maxn],s[maxn];
stack<int> v;
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]),s[i]=s[i-1]+a[i];
    ll ans=0;
    for(int i=n;i>=0;i--)
    {
        while(!v.empty() && s[v.top()]>=s[i])v.pop();
        if(!v.empty())ans+=n+1-v.top();
        v.push(i);
    }
    printf("%lld\n",ans);
    return 0;
}
