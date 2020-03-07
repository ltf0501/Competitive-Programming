#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
#define pii pair<int,int>
#define x first
#define y second
int n,m,r,k;
bool check(int x,int y){return x>0 && x<=n && y>0 && y<=m;}
struct P
{
    int x,y;
    ll val;
    bool operator < (const P& rhs)const{return val<rhs.val;}
};
priority_queue<P> pq;
map<pii,int> mp;
ll cal(int x,int y){return 1ll*(min(n+1,x+r)-max(x,r))*(min(m+1,y+r)-max(y,r));}
main()
{
    scanf("%d%d%d%d",&n,&m,&r,&k);
    ll tot=1ll*(n-r+1)*(m-r+1);
    ll ans=0;
    int a=(n+1)/2,b=(m+1)/2;
    P st={a,b,cal(a,b)};
    mp[pii(a,b)]=1;pq.push(st);
    for(int i=0;i<k;i++)
    {
        P t=pq.top();pq.pop();
        pii node=pii(t.x,t.y);
        ans+=cal(t.x,t.y);
        //printf("%d %d %lld\n",t.x,t.y,cal(t.x,t.y));
        for(int j=0;j<4;j++)
        {
            int x=t.x+dx[j],y=t.y+dy[j];
            if(!check(x,y) || mp.find(pii(x,y))!=mp.end())continue;
            pq.push({x,y,cal(x,y)});
            mp[pii(x,y)]=1;
        }
    }
    //printf("%lld\n",ans);
    printf("%.10f\n",(double)ans/(double)tot);
    return 0;
}
