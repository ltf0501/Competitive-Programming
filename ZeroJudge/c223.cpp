#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 1000010
queue<ll> q2;
ll a[maxn];
main()
{
    int n;
    while(~scanf("%d",&n) && n)
    {
        while(!q2.empty())q2.pop();
        for(int i=0;i<n;i++)scanf("%lld",&a[i]);
        sort(a,a+n);
        ll ans=0;
        int now=0;
        for(int i=0;i<n-1;i++)
        {
            if(now==n)break;
            ll c[2];
            for(int j=0;j<2;j++)
            {
                if(now<n && !q2.empty())
                {
                    if(a[now]<q2.front())c[j]=a[now++];
                    else {c[j]=q2.front();q2.pop();}
                }
                else if(now==n){c[j]=q2.front();q2.pop();}
                else c[j]=a[now++];
            }
            ans+=(c[0]+c[1]);
            q2.push(c[0]+c[1]);
        }
        while(q2.size()>1)
        {
            ll a=q2.front();q2.pop();
            ll b=q2.front();q2.pop();
            ans+=(a+b);
            q2.push(a+b);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
