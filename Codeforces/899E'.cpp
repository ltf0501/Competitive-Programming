///AC
#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int n;
int a[maxn];
int cnt[maxn];
struct P
{
    int pos,cnt;
    bool operator < (const P& b)const
    {
        if(cnt!=b.cnt)return cnt>b.cnt;
        return pos<b.pos;
    }
};
set<P> s1;
set<int> s2;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==a[i-1])cnt[i]=cnt[i-1]+1;
        else cnt[i]=1;
        if(a[i]!=a[i+1])s1.insert({i,cnt[i]}),s2.insert(i);
    }
    s1.insert({0,0}),s1.insert({n+1,0});
    s2.insert(0),s2.insert(n+1);
    int ans=0;
    while(1)
    {
        auto u=s1.begin();P t=*u;
        if(t.cnt==0)break;
        s1.erase(s1.begin());
        auto x=s2.find(t.pos);
        auto y=x;
        x--,y++;
        s2.erase(s2.find(t.pos));
        ans++;
        if(a[*x]==a[*y])
        {
            s1.erase({*x,cnt[*x]});
            s1.erase({*y,cnt[*y]});
            cnt[*y]+=cnt[*x];
            s1.insert({*y,cnt[*y]});
            s2.erase(x);
        }
    }
    //puts("");
    printf("%d\n",ans);
    //for(int i=1;i<=n;i++)printf("%d ",nxt[i]);
    return 0;
}
/*
8
1 2 2 3 3 2 2 1
26
1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 6 6 6 6 6 6 5 4 3 2 1
*/

