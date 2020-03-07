#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int ans[maxn];
int num[maxn];
int r[maxn];
struct P
{
    int num,pos;
    bool operator < (const P& rhs)const
    {
        if(num!=rhs.num)return num<rhs.num;
        return r[pos]>r[rhs.pos];
    }
};
priority_queue<P> pq;
int k,p,q,n;
bool solve()
{
    if(!num[p] || !num[q])return 0;
    if(n==1 && p==q && num[p]==1){ans[1]=p;return 1;}
    if(p==q && num[p]==1)return 0;
    num[p]--,num[q]--;
    ans[1]=p,ans[n]=q;
    for(int i=1;i<=k;i++)if(i!=p && num[i])pq.push({num[i],i});
    int cur=p;
    for(int i=2;i<=n-1;i++)
    {
        if(pq.empty())return 0;
        P u=pq.top();pq.pop();
        ans[i]=u.pos;
        num[u.pos]--;
        if(num[cur])pq.push({num[cur],cur});
        cur=u.pos;
    }
    if(ans[n-1]==q)return 0;
    return 1;
}
main()
{
    scanf("%d%d%d",&k,&p,&q);
    for(int i=1;i<=k;i++)scanf("%d",&num[i]),n+=num[i];
    r[q]=1;
    int cnt=1;
    for(int i=1;i<=k;i++)if(i!=q)r[i]=++cnt;
    if(!solve())puts("0");
    else
    {
        for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
    }
    return 0;
}
