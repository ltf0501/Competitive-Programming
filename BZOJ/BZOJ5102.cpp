#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
struct P
{
    int l,r,id;
    bool operator < (const P& b)const
    {
        return r>b.r;
    }
}p[maxn];
bool cmp(P a,P b){return a.l<b.l;}
priority_queue<P> pq;
main()
{
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int l,r;scanf("%d%d",&l,&r);
        p[i]={l,r,i};
    }
    sort(p+1,p+n+1,cmp);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        pq.push(p[i]);
        if(i>k)pq.pop();
        if(i>=k)ans=max(ans,pq.top().r-p[i].l);
    }
    printf("%d\n",ans);
    while(!pq.empty())pq.pop();
    for(int i=1;i<=n;i++)
    {
        pq.push(p[i]);
        if(i>k)pq.pop();
        if(i>=k)
        {
            if(pq.top().r-p[i].l==ans)
            {
                while(!pq.empty())
                {
                    printf("%d ",pq.top().id);
                    pq.pop();
                }
                return 0;
            }
        }
    }
    return 0;
}
/*
6 3
3 8
4 12
2 6
1 10
5 9
11 12
*/
