#include<bits/stdc++.h>
using namespace std;
#define ll long long
priority_queue<ll,vector<ll>,greater<ll> > pq;
main()
{
    int n,k;scanf("%d%d",&n,&k);
    ll ans=0;
    for(int i=1;i<=(k-(n%k)+1)%k;i++)pq.push(0);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        pq.push(x);
    }
    k++;
    while(!pq.empty())
    {
        ll sum=0;
        for(int i=1;i<=k;i++)
        {
            ll t=pq.top();pq.pop();
            if(i==1 && pq.empty())return 0*printf("%lld\n",ans);
            sum+=t;
        }
        ans+=sum;
        //printf("%lld\n",sum);
        pq.push(sum);
    }
    return 0;
}
