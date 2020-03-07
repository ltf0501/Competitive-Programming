#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
#define maxn 1000010
pii p[maxn];
int A[maxn],B[maxn];
struct node
{
    int x,y;
    bool operator < (const node& b) const
    {
        return y<b.y;
    }
}q[maxn];
priority_queue<node> pq;
vector<pii> v;
int a,b,n;
bool check(int k)
{
    while(!pq.empty())pq.pop();
    int now=1;
    for(int i=1;i<=a;i++)
    {
        while(now<=n && q[now].x<=A[i])pq.push(q[now]),now++;
        int cnt=0;
        while(!pq.empty() && cnt<k)pq.pop(),cnt++;
    }
    for(int i=1;i<=b;i++)
    {
        while(now<=n && q[now].y<=B[i])pq.push(q[now]),now++;
        int cnt=0;
        while(!pq.empty() && cnt<k)pq.pop(),cnt++;
    }
    return pq.empty() && (now==n+1);
}
main()
{
    scanf("%d%d%d",&a,&b,&n);
    for(int i=1;i<=a;i++)scanf("%d",&A[i]);
    for(int i=1;i<=b;i++)scanf("%d",&B[i]);
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i].F,&p[i].S);
    sort(A+1,A+a+1);
    sort(B+1,B+b+1);
    sort(p+1,p+n+1);
    for(int i=n;i>=1;i--)
    {
        if(A[a]<p[i].F)v.push_back(p[i]);
        else break;
    }
    for(pii k : v)
    if(B[b]<k.S){puts("-1");return 0;}
    for(int i=1;i<=n;i++)
    for(int i=1;i<=n;i++)q[i].x=p[i].F,q[i].y=p[i].S;
    int l=1,r=n+1;
    while(r-l>1)
    {
        int m=(l+r)>>1;
        if(check(m))r=m;
        else l=m;
    }
    printf("%d\n",r);
    return 0;
}
