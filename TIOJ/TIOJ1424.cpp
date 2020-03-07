#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+5
priority_queue<int,vector<int>,greater<int> > pq;
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;scanf("%d",&a);
        pq.push(a);
    }
    int sum=0;
    for(int i=1;i<n;i++)
    {
        int s1=pq.top();pq.pop();
        int s2=pq.top();pq.pop();
        sum+=(s1+s2);
        pq.push(s1+s2);
    }
    printf("%d\n",sum);
    return 0;
}
