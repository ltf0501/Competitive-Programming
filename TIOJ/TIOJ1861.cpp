#include<bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        priority_queue<ll, vector<ll>, greater<ll> > pq;
        for(int i=0;i<n;i++)
        {
            ll a;scanf("%lld",&a);
            pq.push(a);
        }
        ll sum=0;
        for(int i=0;i<n-1;i++)
        {
            ll a=pq.top();pq.pop();
            ll b=pq.top();pq.pop();
            sum+=a+b;
            pq.push(a+b);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
