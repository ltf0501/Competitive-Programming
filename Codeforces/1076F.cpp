#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define ll long long
const ll INF=1e14;
int n,k;
int x[maxn],y[maxn];
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&x[i]);
    for(int i=1;i<=n;i++)scanf("%d",&y[i]);
    ll pre_x=0,pre_y=0;
    for(int i=1;i<=n;i++)
    {
        ll cur_x=INF,cur_y=INF;
        if(pre_x<=k)
        {
            if((pre_x+x[i]-1)/k<=y[i] && y[i]<=1ll*x[i]*k)
                cur_x=min(cur_x,(pre_x+x[i]-1)/k<y[i] ? 1ll : (pre_x+x[i]-1)%k+1);

            if((pre_x+x[i]-1)/k<y[i] && y[i]<=1ll*(x[i]+1)*k)
                cur_y=min(cur_y,y[i]<=1ll*x[i]*k+1 ? 1ll : y[i]-1ll*x[i]*k);
        }
        if(pre_y<=k)
        {
            if((pre_y+y[i]-1)/k<=x[i] && x[i]<=1ll*y[i]*k)
                cur_y=min(cur_y,(pre_y+y[i]-1)/k<x[i] ? 1ll : (pre_y+y[i]-1)%k+1);

            if((pre_y+y[i]-1)/k<x[i] && x[i]<=1ll*(y[i]+1)*k)
                cur_x=min(cur_x,x[i]<=1ll*y[i]*k+1 ? 1ll : x[i]-1ll*y[i]*k);
        }
        //printf("%lld %lld\n",cur_x,cur_y);
        pre_x=cur_x,pre_y=cur_y;
    }
    if(pre_x>k && pre_y>k)puts("NO");
    else puts("YES");
    return 0;
}
