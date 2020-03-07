#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > pq;
main()
{
    int n,m;scanf("%d%d",&n,&m);
    while(m--)pq.push(0);
    int ans=0;
    while(n--)
    {
        int x;scanf("%d",&x);
        int s=pq.top();pq.pop();
        pq.push(s+x);
        ans=max(ans,s+x);
    }
    printf("%d\n",ans);
    return 0;
}
