#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
struct P
{
    int id,h,b;
}s[maxn];
deque<P> q;
main()
{
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)s[i].id=i;
    for(int i=1;i<=n;i++)scanf("%d",&s[i].h);
    for(int i=1;i<=n;i++)scanf("%d",&s[i].b);
    int now=0,ans=-1010;
    int l=1,cur=0;
    for(int r=1;r<=n;r++)
    {
        while(!q.empty() && s[r].id-q.front().id>=k)cur-=q.front().b,q.pop_front();
        while(!q.empty() && s[r].h>=q.back().h)cur-=q.back().b,q.pop_back();
        q.push_back(s[r]);cur+=s[r].b;
        if(cur>ans)ans=cur,now=r;
    }
    printf("%d %d\n",now,ans);
    return 0;
}
