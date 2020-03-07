#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int n;
ll a,b;
struct P
{
    ll x,y;
    bool operator < (const P& c)const
    {
        if(a*x-y!=a*c.x-c.y)return a*x-y<a*c.x-c.y;
        return x<c.x;
    }
}v[maxn];
vector<int> vv;
main()
{
    scanf("%d%lld%lld",&n,&a,&b);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d%lld%lld",&x,&v[i].x,&v[i].y);
    }
    sort(v+1,v+n+1);
    //for(int i=1;i<=n;i++)printf("%lld %lld: %lld\n",v[i].x,v[i].y,a*v[i].x-v[i].y);
    ll ans=0;
    int num=0,cur=0;
    for(int i=1;i<=n;i++)
    {
        if(i!=1 && v[i-1].x==v[i].x && v[i-1].y==v[i].y)cur++,num++;
        else if(i==1 || a*v[i-1].x-v[i-1].y<a*v[i].x-v[i].y)
        {
            vv.push_back(cur);
            //printf("%d\n",num);
            ans+=1ll*num*(num-1);
            num=1,cur=1;
            for(int s : vv)ans-=1ll*s*(s-1);
            //for(int s : vv)printf("%d ",s);puts("");
            vv.clear();
        }
        else
        {
            num++;
            vv.push_back(cur);
            cur=1;
        }
    }
    vv.push_back(cur);
    ans+=1ll*num*(num-1);
    for(int s : vv)ans-=1ll*s*(s-1);
    //printf("%d\n",num);
    //for(int s : vv)printf("%d ",s);puts("");
    //for(int s : vv)printf("%d ",s);puts("");
    printf("%lld\n",ans);
    return 0;
}
